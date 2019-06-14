/*
** EPITECH PROJECT, 2019
** lib
** File description:
** clean string
*/

#include <stdlib.h>
#include "my.h"

int is_space(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

int end_of_string(char const *str, int i)
{
    for (; str[i]; i++)
        if (!is_space(str[i]))
            return 0;
    return 1;
}

void otp_char(char const *str, int i, char *buf)
{
    static int space = 0;
    static int j = 0;

    if (i == -1) {
        j = 0;
        return;
    }
    if (is_space(str[i])) {
        if (!space && !end_of_string(str, i)) {
            buf[j++] = ' ';
            space = 1;
        }
    } else {
        buf[j++] = str[i];
        space = 0;
    }
}

char *clean_str(char const *str)
{
    char *s = my_calloc(sizeof(char), my_strlen(str) + 1);
    int i = 0;

    for (i = 0; is_space(str[i]); i++);
    for (; str[i]; i++)
        otp_char(str, i, s);
    otp_char(str, -1, s);
    return s;
}
