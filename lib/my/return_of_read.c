/*
** EPITECH PROJECT, 2020
** fs_understand_return_of_read
** File description:
** read
*/

#include "../../include/bsq.h"

int return_of_read(int fd, char *buffer, int size)
{
    int read_size = read(fd, buffer, size);

    buffer[size] = '\0';
    if (read_size == -1) {
        return (ERROR);
    } else if (read_size == 0) {
        return (ERROR);
    } else if (read_size < size) {
        return (ERROR);
    } else if (read_size == size) {
        return (read_size);
    }
}
