# Get Next Line

## Descripción

Get Next Line es un proyecto cuyo objetivo es implementar una función capaz de leer un archivo o una entrada y devolver una línea completa cada vez que es llamada.

Este proyecto permite comprender el funcionamiento de los file descriptors, la lectura de archivos mediante buffers y la gestión de memoria dinámica en C.

## Función principal

```c
char *get_next_line(int fd);
```

La función devuelve la siguiente línea disponible del archivo asociado al descriptor `fd`, incluyendo el carácter de salto de línea (`\n`) cuando existe.

Cada llamada sucesiva devuelve la siguiente línea hasta llegar al final del archivo.

## Conceptos trabajados

- File descriptors
- Lectura de archivos con `read`
- Buffers
- Memoria dinámica
- Variables estáticas
- Gestión de cadenas
- Manejo de errores

## Compilación

Para compilar el proyecto:

```bash
make
```

### Reglas disponibles

```bash
make
make clean
make fclean
make re
```

## Uso

### Ejemplo

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

## Funcionamiento

La función:

1. Lee datos desde un descriptor de archivo utilizando un buffer de tamaño `BUFFER_SIZE`.
2. Almacena temporalmente la información leída.
3. Extrae una línea completa.
4. Conserva los datos restantes para la siguiente llamada.
5. Continúa hasta alcanzar el final del archivo.

## Gestión de errores

La función devuelve `NULL` cuando:

- Se alcanza el final del archivo.
- El descriptor de archivo es inválido.
- Se produce un error durante la lectura.
- Falla una reserva de memoria.

## Objetivo

El objetivo principal es aprender a gestionar lecturas parciales de archivos y mantener información entre llamadas a una función utilizando memoria dinámica y variables estáticas.

## Autor

Proyecto realizado como parte del programa de formación de 42.
