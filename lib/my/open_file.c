/*
** EPITECH PROJECT, 2020
** Istep1
** File description:
** open a file
*/

#include "../../include/bsq.h"

int open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        write(2, OPEN_ERROR, 10);
    return (fd);
}
