/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/
#ifndef MYH
    #define MYH

void create_func(char **env, char *line);

int my_delim(char c, int nbr);

void suit_func(char **env, char **arr2, char **tab);

int len(char *str, int x);

int count(char *str);

char **my_str_to_word_array(char *str);

void print_arg(char **arg);

int fs_get_number_from_first_line(char const *filepath);

char *load_file_in_mem(char const *filepath);

void my_putchar(char c);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

char *my_int_to_string(int value);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_string_to_int(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

int my_read(int nb, int n);
#endif
