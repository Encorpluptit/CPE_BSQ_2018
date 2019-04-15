/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Unit test for fct get_main_str.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bsq.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(get_main_str, test_01)
{
    char *res = my_strdup("2\ncoucou\ncoucou\n");
    char *src = get_main_str("tests/coucou");

    cr_assert_str_eq(src, res, "resultat = %s", src);
}
