/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** find the bigger square
*/

#include "bsq.h"

char *cut_buffer(char *buffer)
{
    int i = 0;

    for (; buffer[i] != '.' && buffer[i] != 'o'; i += 1) {
    }
    buffer = &buffer[i];
    return (buffer);
}

char *create_buffer(char *buffer, int fd, long int size_buffer)
{
    int read_size;

    read_size = return_of_read(fd, buffer, size_buffer);
    if (read_size == ERROR)
        return (READ_ERROR);
    buffer = cut_buffer(buffer);
    return (buffer);
}

long int *create_size(long int *size, char *buffer, long int size_buffer)
{
    long int size_line;

    size_line = line_size(buffer, size_buffer);
    size[0] = size_line;
    size[1] = size_buffer;
    return (size);
}

int bsq(char const *filepath)
{
    my_square bigger = {0, 0};
    char *buffer;
    int fd = open_file(filepath);
    long int size_buffer;
    struct stat buf;
    long int *size = malloc(sizeof(long int) * 3);

    if (fd == -1)
        return (ERROR);
    stat(filepath, &buf);
    size_buffer = buf.st_size;
    buffer = malloc(sizeof(char) * size_buffer + 1);
    buffer = create_buffer(buffer, fd, size_buffer);
    if (error_handling(buffer, size_buffer) == ERROR)
        return (ERROR);
    size = create_size(size, buffer, my_strlen(buffer));
    do_bsq(buffer, size, bigger, fd);
    return (0);
}
