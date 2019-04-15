/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** unit test for checking return of stat_fct.
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <fcntl.h>
#include "bsq.h"

Test(fct_stat, test_01)
{
    int fd = open("tests/test", O_RDONLY);
    int res = fct_stat("tests/test");
    close(fd);

    cr_assert_eq(res, 10104, "resultat = %d", res);
}

Test(fct_stat, test_02)
{
    int fd = open("tests/test", O_RDONLY);
    int res = fct_stat("test");
    close(fd);

    cr_assert_eq(res, -1, "resultat = %d", res);
}
