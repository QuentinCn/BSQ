/*
** EPITECH PROJECT, 2020
** BSQ.h
** File description:
** .h of BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define ERROR 84
#define READ_ERROR "read error"
#define ARG_ERROR "incorrect number of argument"
#define LINE_ERROR "line size error"
#define BUF_ERROR "invalid buffer"
#define OPEN_ERROR "open error"

struct size_square
{
    int place;
    int width;
};

typedef struct size_square my_square;

void my_putchar(char c);
int my_putstr(char *str);
int my_put_nbr(int nb);
int open_file(char const *filepath);
int return_of_read(int fd, char *buffer, int size);
int error_handling(char *buffer, long int size_buffer);
long int line_size(char *buffer, long int size_buffer);
my_square dot_case(char *buffer, long int *size, int i, my_square new);
my_square find_bigger_square(char *buffer, long int *size, my_square bigger);
void display_square(char *buffer, long int *size, my_square bigger);
int my_strlen(char *str);
void do_bsq(char *buffer, long int *size, my_square bigger, int fd);
