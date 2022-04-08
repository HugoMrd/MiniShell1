/*
** EPITECH PROJECT, 2022
** mino
** File description:
** mino
*/

#include <string.h>
#include "../include/my.h"
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

void suit_func(char **env, char **arr2, char **tab)
{
    for (int b = 0; arr2[b] != NULL; b++)
        execve(arr2[b], tab, env);
}

void my_cd(char **env, char **tab)
{
    char **home;

    for (int a = 0; env[a] != NULL; a++) {
        if (my_strncmp(env[a], "HOME", 4) == 0)
            home = my_str_to_word_array(env[a]);
    }
    if (my_strcmp(tab[0], "cd") == 0) {
        if (tab[1] == NULL)
            chdir(home[1]);
        else
            chdir(tab[1]);
    }
}

void create_func (char **env, char *line)
{
    char **tab = my_str_to_word_array(line);
    int a = 0;

    if (my_strncmp(tab[0], "env", 3) == 0) {
        for (int i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            my_putchar('\n');
        }
    }
    if (my_strcmp(tab[0], "exit") == 0) {
        a = my_getnbr(line);
        if (a == 0)
            exit(0);
        else
            exit(a);
    }
    my_cd(env, tab);
}
