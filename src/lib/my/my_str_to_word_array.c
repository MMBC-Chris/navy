/*
** EPITECH PROJECT, 2019
** lib
** File description:
** stwa
*/

#include <stdlib.h>
#include "my.h"

int is_wsep(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

int my_strwlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] && !is_wsep(str[i]); i++);
    return i;
}

char *my_strwdup(char const *str)
{
    int len = my_strwlen(str);
    char *dup = malloc(sizeof(char) * (len + 1));

    dup[len] = '\0';
    for (int i = 0; i < len; i++)
        dup[i] = str[i];
    return dup;
}

char **my_str_to_word_array(char const *str)
{
    char **arr;
    int count = 0;
    int offset = 0;

    for (int i = 0; str[i]; i++)
        if (is_wsep(str[i]))
            count++;
    count++;
    arr = malloc(sizeof(char **) * (count + 1));
    arr[count] = NULL;
    for (int i = 0; i < count; i++) {
        arr[i] = my_strwdup(str + offset);
        offset += my_strlen(arr[i]) + 1;
    }
    return arr;
}
