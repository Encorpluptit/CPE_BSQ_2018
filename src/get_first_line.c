/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** fct for wiping first line and getting number of line.
*/

#include "bsq.h"
#include <stdlib.h>

int get_first_line(char const *str)
{
    int i = 0;
    int nb_ligne = 0;
    char *tmp;

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++);
    tmp = malloc(sizeof(char) * (i + 1));
    if (tmp == NULL)
        return (-1);
    for (i = 0; str[i] != '\n'; i++) {
        if (is_numeric(str[i]) == 0 || str[i] == '\0')
            return (-1);
        else
            tmp[i] = str[i];
    }
    tmp[i] = '\0';
    nb_ligne = my_atoi(tmp);
    str = str + (i + 1);
    free(tmp);
    return (nb_ligne);
}

int get_nb_column(char const *str)
{
    unsigned int i = 0;

    for (i = 0; str[i] != '\n' && str[i] != '\0'; i++);
    return (i + 1);
}

int wipe_first_line(char **main_str)
{
    int i = 0;
    int nb_lign = 0;
    char *tmp;

    for (i = 0; (*main_str)[i] != '\0' && (*main_str)[i] != '\n'; i++);
    tmp = malloc(sizeof(char) * (i + 1));
    if (tmp == NULL)
        return (-1);
    for (i = 0; (*main_str)[i] != '\n'; i++) {
        if (is_numeric((*main_str)[i]) == 0 || (*main_str)[i] == '\0')
            return (-1);
        else
            tmp[i] = (*main_str)[i];
    }
    tmp[i] = '\0';
    nb_lign = my_atoi(tmp);
    *main_str = *main_str + (i + 1);
    free(tmp);
    return (nb_lign);
}
