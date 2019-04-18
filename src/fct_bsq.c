/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** fonction for the algo of bsq
*/

#include "bsq.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static short make_calcul(short left_case, short up_case, short upleft_case)
{
    if (left_case < up_case) {
        if (left_case < upleft_case)
            return (left_case + 1);
        else
            return (upleft_case + 1);
    }
    else if (up_case < upleft_case)
        return (up_case + 1);
    else
        return (upleft_case + 1);
}

static void maximum(int *ptri, int i, short arr)
{
    static short maximum = 0;

    if (arr > maximum) {
        maximum = arr;
        *ptri = i;
    }
}

static short *fill_array(short *arr, char const *str, int nb_column, int *ptri)
{
    int i = 0;
    int j = 1;

    for (i = 0; str[i] != '\0'; i++) {
        str[i] == '.' ? arr[i] = 1 : 0;
        if (str[i] != 'o' && str[i] != '.' && str[i] != '\n') {
            write(2, "Invalid Map, please use a valid file.\n", 38);
            return NULL;
        }
        if (str[i] == '.' && i > nb_column && (i % (nb_column * j)) != 0) {
            arr[i] = make_calcul(arr[i - 1], arr[i - nb_column],
                                arr[i - nb_column - 1]);
        }
        maximum(ptri, i, arr[i]);
        (i != nb_column) && (i % (nb_column * j)) == 0 ? j++ : 0;
        str[i] == 'o' ? arr[i] = 0 : 0;
        str[i] == '\n' ? arr[i] = -1 : 0;
    }
    str[i] == '\0' ? arr[i] = -2 : 0;
    return (arr);
}

static void print_bsq(char *main_str, int index, int nb_column, int square_size)
{
    int begin = index - ((square_size - 1) * nb_column) - (square_size - 1);
    int i = begin;
    short flag = -1;
    int end = my_strlen(main_str);

    write(1, main_str, begin);
    for (int j = 0; i <= index; i++) {
        while (i >= (begin + (nb_column * j)) &&
            i < begin + (nb_column * j) + square_size && j < square_size) {
            write(1, "x", 1);
            i++;
            flag = 1;
        }
        write(1, &main_str[i], 1);
        flag == 1 ? j++ : 0;
        flag = 0;
    }
    write(1, main_str + i, end - i);
}

int fct_bsq(char *main_str)
{
    int nb_lign = wipe_first_line(&main_str);
    int nb_column = get_nb_column(main_str);
    short *arr = malloc(sizeof(short) * (nb_lign * nb_column + 1));
    int ptri = 0;

    arr = fill_array(arr, main_str, nb_column, &ptri);
    if (arr == NULL)
        return (84);
    print_bsq(main_str, ptri, nb_column, arr[ptri]);
    free(arr);
    return (0);
}
