/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** stat_fct, for getting size of a file in bits to know size of main string.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "stdlib.h"

int fct_stat(char const *filepath)
{
    struct stat *statbuf = malloc(sizeof(struct stat));
    int str_len = 0;
    int check = 0;

    check = stat(filepath, statbuf);
    if (check == -1)
        return (-1);
    else
        str_len = statbuf->st_size;
    free(statbuf);
    return(str_len);
}
