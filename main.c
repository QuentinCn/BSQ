/*
** EPITECH PROJECT, 2020
** main
** File description:
** main bsq
*/

#include "bsq.h"

int bsq(char const *filepath);

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, ARG_ERROR, 28);
        return (84);
    }
    if (bsq(av[1]) == ERROR)
        return (ERROR);
    return (0);
}
