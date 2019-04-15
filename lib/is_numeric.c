/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** fct for checking if character is numeric.
*/

int is_numeric(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}
