/*
** EPITECH PROJECT, 2022
** stwa
** File description:
** stwa
*/

#include "../../include/my.h"
#include <stdlib.h>

int my_delim(char c, int nbr)
{
    if (nbr == 1 && c >= 33 && c <= 126 && c != ':' && c != '='
        && c != '\t' && c != '\v')
        return (1);
    return (0);
}

int len(char *str, int x)
{
    for (x = 0; str[x] != '\0'; x++) {
        if (my_delim(str[x], 1) != 1)
            return (x);
        x++;
    }
    return (x);
}

int count(char *str)
{
    int x = 0;
    int count = 0;

    for (x = 0; str[x] != '\0'; x++) {
        if (my_delim(str[x], 1) == 1 && my_delim(str[x + 1], 1) != 1) {
            count += 1;
        }
    }
    return (count);
}

char **my_str_to_word_array(char *str)
{
    int deta = 0;
    int y = 0;
    int x = 0;
    int nbr_delim = count(str);
    char **res = malloc(sizeof(char *) * (nbr_delim + 1));

    for (y = 0; y < nbr_delim && str[x] != '\0'; y++, x++) {
        while (str[x] != '\0' && my_delim(str[x], 1) == 0)
            x++;
        deta = 0;
        res[y] = malloc(sizeof(char) * (len(str, x) + 500000));
        while (str[x] != '\0' && my_delim(str[x], 1) != 0) {
            res[y][deta] = str[x];
            deta++;
            x++;
        }
        res[y][deta] = '\0';
    }
    res[y] = NULL;
    return (res);
}
