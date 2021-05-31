/*
** EPITECH PROJECT, 2020
** error_handling
** File description:
** handle error
*/

#include "../../include/bsq.h"

long int line_size(char *buffer, long int size_buffer)
{
    int x = 0;
    int size_line = 0;

    for (; buffer[x] != '\n'; x += 1) {
        size_line += 1;
    }
    for (int i = x; buffer[i + 1] != '\0'; i += size_line + 1) {
        if (buffer[i] != '\n') {
            return (ERROR);
        }
    }
    return (size_line);
}

int error_handling(char *buffer, long int size_buffer)
{
    int size_line;

    for (int i = 0; buffer[i] != '\0'; i += 1) {
        if (buffer[i] != 'o' && buffer[i] != '.' &&
            buffer[i] != '\n' && buffer[i] != '\0') {
            write(2, BUF_ERROR, 14);
            return (ERROR);
        }
    }
    if (line_size(buffer, size_buffer) == ERROR) {
        write(2, LINE_ERROR, 15);
        return (ERROR);
    }
    return (0);
}
