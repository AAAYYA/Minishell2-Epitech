/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-damian.gil
** File description:
** str_double_del
*/

#include "includes/mysh.h"

int mallocs(char *str, char del, int send_it, char delim)
{
    int i = send_it;
    while (str[i] != del && str[i] != '\0' && str[i] != delim) {
        i++;
    }
    return i;
}

void my_memory_clean(char **array)
{
    int a = 0;
    while (array[a] != NULL) {
        free(array[a]);
        a++;
    }
    free(array);
}

int my_wordlen(char *str, int a, char d)
{
    int b = 0;
    while (str[a - 1] != d) {
        a++;
        b++;
    }
    return b;
}

int fetch_d(char const *str, char del, char delim)
{
    int i = 1;
    for (int n = 0; n < my_strlen(str); n++)
        if (str[n] == del || str[n] == delim)
            i++;
    return i;
}

char **my_str_to_array(char *str, char del, char delim)
{
    char **word = malloc(sizeof(char *) * (fetch_d(str, del, delim) + 1));
    int count = 0, y = 0, send_it = 0, tmp = 0, n = 0, i = 0;
    for (i = 0; i < fetch_d(str, del, delim); i++) {
        tmp = mallocs(str, del, send_it, delim);
        word[i] = frees(tmp + 2);
        send_it += tmp;
    }
    for (n = 0; str[n] != '\0'; n++) {
        if (str[n] == del || str[n] == delim) {
            word[count][y] = '\0';
            count++;
            y = 0;
        } else {
            word[count][y] = str[n];
            y += 1;
        }
    }
    word[count + 1] = NULL;
    return word;
}
