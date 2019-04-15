/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** header for all bsq fct.
*/

#ifndef __BSQ_H__
#define __BSQ_H__

int fct_stat(char const *filepath);
char *get_main_str(char const *filepath);
int get_first_line(char const *str);

int fct_bsq(char *main_str);
//short make_calcul(short left_case, short up_case, short upleft_case);
int wipe_first_line(char **main_str);
int get_nb_column(char const *str);

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *str);
int is_numeric(char c);
int my_atoi(char const * const str);

#endif
