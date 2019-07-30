/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** alllocate memory and copy a string given as a argument
*/

#include <stdlib.h>
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    int src_len = my_strlen(src);
    char *dest;

    dest = malloc(sizeof(char) * src_len);
    dest = my_strcpy(dest, src);
    dest[src_len] = '\0';
    return dest;
}
