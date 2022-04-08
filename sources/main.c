/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
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

int function(char **arr, char **env, char **tab)
{
    char *cat;
    char *final[2];
    char **arr2;

    if (execve(tab[0], tab, env) == -1) {
        for (int a = 1; arr[a] != NULL; a++) {
            cat = my_strcat(arr[a], "/");
            final[0] = my_strcat(cat, tab[0]);
            final[1] = my_strcat(final[0], ":");
            arr2 = my_str_to_word_array(final[1]);
            suit_func(env, arr2, tab);
        }
    }
}

int path(char **env, char **tab)
{
    char **arr;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH", 4) == 0) {
            arr = my_str_to_word_array(env[i]);
            function(arr, env, tab);
        }
    }
    my_putstr(tab[0]);
    my_putstr(": Command not found.\n");
    exit(1);
    return 0;
}

void last(pid_t pid, int status, char **env, char **tab)
{
    if (pid != 0) {
        wait(&status);
        if (WIFSIGNALED(status) && WTERMSIG(status) == 11) {
            my_putstr("Segmentation fault\n");
        }
    } else {
        path(env, tab);
    }
    write(1, "$> ", 3);
}

void init_all(char **env, char *line, char **tab)
{
    int status;
    pid_t pid;

    if (tab[0] != NULL) {
        create_func(env, line);
        pid = fork();
        last(pid, status, env, tab);
    } else
        write(1, "$> ", 3);
}

int main(int ac, char **av, char **env)
{
    pid_t pid;
    int status;
    size_t size_line = 0;
    char *line = NULL;
    char **tab;

    if (ac != 1)
        return 84;
    if (ac == 1) {
        write(1, "$> ", 3);
        while (getline(&line, &size_line, stdin) != -1) {
            tab = my_str_to_word_array(line);
            init_all(env, line, tab);
        }
    }
    return 0;
}
