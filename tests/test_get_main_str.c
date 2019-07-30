/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Unit test for fct get_main_str.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bsq.h"
#include <errno.h>
static int override_malloc;

void *__real_malloc(size_t);
void *__wrap_malloc(size_t s) {
    if (override_malloc) {
        errno = ENOMEM;
        return NULL;
    }
    return __real_malloc(s);
}

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(get_main_str, test_01)
{
    override_malloc = 0;
    char *res = my_strdup("2\ncoucou\ncoucou\n");
    char *src = get_main_str("tests/coucou");

    cr_assert_str_eq(src, res, "resultat = %s", src);
}

Test(get_main_str, test_02)
{
    override_malloc = 1;
    char *src = get_main_str("tests/coucou");
    override_malloc = 0;

    cr_assert_null(src);
}
