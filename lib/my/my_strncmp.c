/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n - 1; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    if (s1[i] == '\0' || s2[i] == '\0')
        return s1[i] - s2[i];
    return 0;
}
