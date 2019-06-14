/*
** EPITECH PROJECT, 2018
** gn
** File description:
** c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char *mncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (src == NULL || dest == NULL)
        return NULL;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}

int slen(char *s)
{
    int i = 0;

    for (; s[i]; i++);
    return i;
}

char *line_to_buf(char *line, int j, char *buf, int *s)
{
    char *new;
    int old;

    if (line)
        old = slen(line);
    else
        old = 0;
    new = malloc((old + j + 1) * sizeof(char));
    if (line)
        mncpy(new, line, old);
    else
        mncpy(new, "", old);
    new[old + j] = '\0';
    mncpy(old + new, buf + *s, j);
    *s += (j + 1);
    return new;
}

void update_line(gnl_t *gnl)
{
    if (gnl->s + gnl->j == gnl->i - 1)
        gnl->line = line_to_buf(gnl->line, gnl->j + 1, gnl->buf, &gnl->s);
}

char *get_next_line(int fd)
{
    static gnl_t gnl = {"", 0, 0, 0, NULL};
    gnl.line = NULL;

    while (1) {
        if (gnl.s >= gnl.i) {
            gnl.s = 0;
            gnl.i = read(fd, gnl.buf, READ_SIZE);
            if (!gnl.i)
                return gnl.line;
            if (gnl.i == -1)
                return NULL;
            gnl.j = 0;
        }
        if (gnl.buf[gnl.s + gnl.j] == '\n' || !gnl.buf[gnl.s + gnl.j]) {
            gnl.line = line_to_buf(gnl.line, gnl.j, gnl.buf, &gnl.s);
            return gnl.line;
        }
        update_line(&gnl);
        gnl.j++;
    }
}
