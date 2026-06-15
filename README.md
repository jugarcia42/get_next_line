# Get Next Line

## About

Get Next Line is a project from the 42 School curriculum that focuses on file descriptor management and buffered reading. The objective is to implement a function capable of reading a file, standard input, or any valid file descriptor line by line, regardless of the size of the file or the number of calls made.

This project provides a deeper understanding of static variables, memory allocation, file descriptors, and efficient input handling in C.

## The Challenge

The goal is to implement the following function:

```c
char *get_next_line(int fd);
```

Each call to `get_next_line()` must return the next line read from the given file descriptor, including the newline character (`\n`) when present. Once the end of the file is reached, the function must return `NULL`.

The implementation must handle partial reads, manage internal buffers correctly, and work efficiently with different file sizes.

## Features

- Reads from any valid file descriptor.
- Returns one line per function call.
- Handles files of any size.
- Supports standard input reading.
- Efficient buffer management.
- Preserves unread data between calls.
- Proper memory allocation and cleanup.
- Bonus support for multiple file descriptors simultaneously.

## Usage

Compile the project:

```bash
make
```

Include the header in your source code:

```c
#include "get_next_line.h"
```

Example:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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

## Project Structure

```text
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── Makefile
└── README.md
```

## Compilation

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

The compilation generates the object files required for integration into other projects.

## How It Works

### Reading Data

The function reads data from the file descriptor using the `read()` system call and stores it in an internal buffer.

### Buffer Management

A static variable is used to preserve any unread data between function calls, allowing the function to continue exactly where it left off.

### Line Extraction

The stored buffer is searched for a newline character. When one is found, the corresponding line is extracted and returned while the remaining data is kept for future calls.

### End of File

When no more data can be read and all buffered content has been returned, the function returns `NULL`.

## Bonus Part

The bonus version supports reading from multiple file descriptors simultaneously by maintaining independent buffers for each descriptor.

This allows the program to alternate calls between different files without losing any state.

## Learning Objectives

Through this project, I gained experience with:

- File descriptor management.
- Static variables.
- Dynamic memory allocation.
- Buffer handling.
- String manipulation.
- Efficient input processing.
- Resource management.
- Low-level file operations.

## Technologies

- C
- Unix/Linux System Calls
- File Descriptors
- Dynamic Memory Management
- Makefile


Developed as part of the 42 School curriculum.
