/*
** EPITECH PROJECT, 2019
** lib
** File description:
** stwa
*/

#include <stdlib.h>
#include "my.h"

static int my_strslen(char const *str, char sep)
{
    int i = 0;

    for (i = 0; str[i] && str[i] != sep; i++);
    return i;
}

static char *my_strsdup(char const *str, char sep)
{
    int len = my_strslen(str, sep);
    char *dup = malloc(sizeof(char) * (len + 1));

    dup[len] = '\0';
    for (int i = 0; i < len; i++)
        dup[i] = str[i];
    return dup;
}

char **my_str_sep(char const *str, char sep)
{
    char **arr;
    int count = 0;
    int offset = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == sep)
            count++;
    count++;
    arr = malloc(sizeof(char **) * (count + 1));
    arr[count] = NULL;
    for (int i = 0; i < count; i++) {
        arr[i] = my_strsdup(str + offset, sep);
        offset += my_strlen(arr[i]) + 1;
    }
    return arr;
}
