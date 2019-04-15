/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Main fct for getting main string executing bsq (main fct) and free string.
*/

#include "bsq.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    char *main_str;

    main_str = get_main_str(av[1]);
    if (main_str == NULL) {
        write(2, "Invalid Map, please use a valid file.\n", 38);
        return (84);
    }
    fct_bsq(main_str);
    free (main_str);
    return (0);
}
