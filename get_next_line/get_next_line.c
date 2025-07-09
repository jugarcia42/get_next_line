/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:28:27 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/16 21:43:23 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*buffreader(int fd, char *statstr)
{
	char	*tempbuff;
	int		numread;

	numread = 1;
	tempbuff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tempbuff)
		return (NULL);
	tempbuff[0] = '\0';
	while (numread > 0 && !ft_strchr(tempbuff, '\n'))
	{
		numread = read(fd, tempbuff, BUFFER_SIZE);
		if (numread > 0)
		{
			tempbuff[numread] = '\0';
			statstr = ft_strjoin(statstr, tempbuff);
		}
	}
	free(tempbuff);
	if (numread == -1)
		return (ft_free(&statstr));
	return (statstr);
}

char	*setnextstat(char *statstr, char *nextline)
{
	char	*newstatic;
	int		len;

	if (nextline == NULL)
	{
		newstatic = NULL;
		return (ft_free(&statstr));
	}
	else
		len = (nextline - statstr) + 1;
	if (!statstr[len])
		return (ft_free(&statstr));
	newstatic = ft_substr(statstr, len, ft_strlen(statstr) - len);
	ft_free(&statstr);
	if (!newstatic)
		return (NULL);
	return (newstatic);
}

char	*get_next_line(int fd)
{
	static char	*statstr;
	char		*line;
	char		*ptr;

	if (fd < 0)
		return (NULL);
	if ((statstr && !ft_strchr(statstr, '\n')) || !statstr)
		statstr = buffreader(fd, statstr);
	if (!statstr)
		return (NULL);
	ptr = ft_strchr(statstr, '\n');
	line = ft_substr(statstr, 0, (ptr - statstr) + 1);
	if (!line)
		return (ft_free(&statstr));
	statstr = setnextstat(statstr, ptr);
	return (line);
}
