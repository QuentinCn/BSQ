/*
** EPITECH PROJECT, 2020
** find_bigger_square
** File description:
** find the bigger square in the buffer
*/

#include "../../include/bsq.h"

my_square dot_case(char *buffer, long int *size, int i, my_square new)
{
    int x = 1;

    new.place = i;
    for (; buffer[i + x] == '.' && buffer[i + x] != '\0'; x += 1) {
        for (int y = 0; y <= x; y += 1) {
            for (int z = 0; z <= x; z += 1) {
                if (i + z + y * (size[0] + 1) >= size[1]) {
                    new.width = x;
                    return (new);
                }
                if (buffer[i + z + y * (size[0] + 1)] != '.') {
                    new.width = x;
                    return (new);
                }
            }
        }
    }
    new.width = x;
    return (new);
}

my_square find_bigger_square(char *buffer, long int *size, my_square bigger)
{
    my_square new = {0, 0};

    for (int i = 0; buffer[i] != '\0' && i < size[1] - 1; i += 1) {
        if (i + bigger.width * (bigger.width + 1) >= size[1])
            break;
        if (buffer[i] != '.' && buffer[i] != 'o')
            i += 1;
        if (buffer[i] == '.')
            new = dot_case(buffer, size, i, new);
        if (new.width > bigger.width) {
            bigger.place = new.place;
            bigger.width = new.width;
        }
    }
    return (bigger);
}

void display_square(char *buffer, long int *size, my_square bigger)
{
    int k;
    int l = 0;
    int display_from = 0;

    for (int i = bigger.place; l != bigger.width; i += 1) {
        k = 0;
        for (int j = 0; j != bigger.width; j += 1) {
            buffer[i + k * (size[0] + 1)] = 'x';
            k += 1;
        }
        l += 1;
    }
    write(1, buffer, size[1]);
}

void do_bsq(char *buffer, long int *size, my_square bigger, int fd)
{
    bigger = find_bigger_square(buffer, size, bigger);
    display_square(buffer, size, bigger);
    free(size);
    close(fd);
}
