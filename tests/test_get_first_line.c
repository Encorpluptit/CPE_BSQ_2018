/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Unit tests for wipe_first_line.
*/

#include <criterion/criterion.h>
#include "bsq.h"

Test(get_first_line, test_01)
{
    char *str = my_strdup("124\noooo...\n");
    int res = get_first_line(str);

    cr_assert_eq(res, 124, "resultat = %d", res);
}

Test(get_first_line, test_02)
{
    char *str = my_strdup("124\noooo...\n");
    int res = get_first_line(str);
    char *str_modif = my_strdup("oooo...\n");

    cr_assert_eq(res, 124, "resultat = %d", res);
}

Test(get_first_line, test_03)
{
    char *str = my_strdup("12454\noooo...\n");
    int res = get_first_line(str);

    cr_assert_eq(res, 12454, "resultat = %d", res);
}

Test(get_first_line, test_04)
{
    char *str = my_strdup("12a54\noooo...\n");
    int res = get_first_line(str);

    cr_assert_eq(res, -1, "resultat = %d", res);
}

Test(get_first_line, test_05)
{
    char *str = my_strdup("oooo...\n");
    int res = get_first_line(str);

    cr_assert_eq(res, -1, "resultat = %d", res);
}

Test(get_first_line, test_06)
{
    char *str = my_strdup("124");
    int res = get_first_line(str);

    cr_assert_eq(res, -1, "resultat = %d", res);
}

Test(get_first_line, test_07)
{
    char *str = my_strdup("-124");
    int res = get_first_line(str);

    cr_assert_eq(res, -1, "resultat = %d", res);
}

Test(get_first_line, test_08)
{
    char *str = my_strdup("");
    str[0] = '\0';
    int res = get_first_line(str);

    cr_assert_eq(res, -1, "resultat = %d", res);
}

Test(get_nb_column, test_09)
{
    char *str = my_strdup("....ooo.o.ooo...o..o...oo.o..oo..o\n\
....ooo.o.ooo...o..o...oo.o..oo..o");
    int res = get_nb_column(str);

    cr_assert_eq(res, 35, "resultat = %d", res);
}

Test(wipe_first_line, test_10)
{
    char *str = my_strdup("124\n....ooo.o.ooo...o..o...oo.o..oo..o\n\
....ooo.o.ooo...o..o...oo.o..oo..o");
    int res_lign = wipe_first_line(&str);
    char *res_str = my_strdup("....ooo.o.ooo...o..o...oo.o..oo..o\n\
....ooo.o.ooo...o..o...oo.o..oo..o");

    cr_assert_eq(res_lign, 124, "resultat = %d", res_lign);
    cr_assert_str_eq(str, res_str, "resultat = %s", res_str);
}

Test(wipe_first_line, test_11)
{
    char *str = my_strdup("-124\n....ooo.o.ooo...o..o...oo.o..oo..o\n\
....ooo.o.ooo...o..o...oo.o..oo..o");
    int res_lign = wipe_first_line(&str);

    cr_assert_eq(res_lign, -1, "resultat = %d", res_lign);
}

Test(get_nb_column, test_12)
{
    char *str = my_strdup("o.o.o.o.");
    int res = get_nb_column(str);

    cr_assert_eq(res, 9, "resultat = %d", res);
}

Test(get_first_line, test_13)
{
    char *str = my_strdup("a");
    int res = get_first_line(str);

    cr_assert_eq(res, -1, "resultat = %d", res);
}
