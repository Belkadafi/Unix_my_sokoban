/*
** EPITECH PROJECT, 2019
** sting reverser
** File description:
** wallah jsp
*/

int my_strlen(char const *str);
int  my_swap(char *a, char *b);

char *my_revstr(char *str)
{
    int m = my_strlen(str) - 1;
    int u = my_strlen(str);
    int d = 0;

    while (d < (u/2)) {
        my_swap(&str[m], &str[d]);
        m--;
        d++;
    }
    return (str);
}
