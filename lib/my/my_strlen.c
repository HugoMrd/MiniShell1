/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** my_strlen
*/

int my_putchar(char c);

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
