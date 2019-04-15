/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** function for opening the file and get main string out of it.
*/

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int check_open_errors(int fd)
{
    if (fd == -1) {
        write(2, "Read failed.\n", 13);
        return (84);
    }
    else if (fd >= 3)
        return (0);
    else
        return (84);
}

static char *fct_read(int fd, int str_len)
{
    char *buffer = malloc(sizeof(char) * (str_len + 1));

    if (read(fd, buffer, str_len) >= 0)
        buffer[str_len] = '\0';
    return (buffer);
}

static int get_nb_lenght(int nb_lign)
{
    int i = 0;

    for (; nb_lign != 0; i++)
        nb_lign /= 10;
    return (i);
}

static int check_valid_map(char const *main_str, int str_len)
{
    int nb_lign = get_first_line(main_str);
    int nb_lenght = get_nb_lenght(nb_lign);
    int nb_column = 0;
    int i = 0;

    return (0);

    if (nb_lign == -1)
        return (-1);
    for (i = nb_lenght; main_str[i] != '\n' && main_str[i] != '\0'; i++);
    for (i += 1; main_str[i] != '\n' && main_str[i] != '\0'; i++)
        nb_column++;
    if (((nb_column + 1) * nb_lign + nb_lenght + 1) != str_len)
        return (-1);
    else
        return (0);
}

char *get_main_str(char const *filepath)
{
    char *main_str;
    int fd = open(filepath, O_RDONLY);
    int str_len = 0;

    if (check_open_errors(fd) == 84)
        return NULL;
    str_len = fct_stat(filepath);
    if (str_len == -1)
        return NULL;
    else
        main_str = fct_read(fd, str_len);
    if (check_valid_map(main_str, str_len) == -1)
        return NULL;
    close (fd);
    return (main_str);
}
