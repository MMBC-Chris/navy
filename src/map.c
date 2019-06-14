/*
** EPITECH PROJECT, 2019
** navy
** File description:
** map
*/

#include "navy.h"

int strtop(char const *pos)
{
    int ret = 0;

    if (my_strlen(pos) != 2)
        return -1;
    if (*pos < 'A' || *pos > 'H')
        return -1;
    if (pos[1] < '1' || pos[1] > '8')
        return -1;
    ret = (*pos - 'A') << 16;
    ret += pos[1] - '1';
    return ret;
}

char *read_file(char const *filename)
{
    int fd = -1;
    struct stat st;
    char *content;

    if (stat(filename, &st) == -1) {
        my_errstr(TBRD "Error:" TRST " could not open fille\n");
        return NULL;
    }
    content = my_calloc(sizeof(char), (st.st_size + 1));
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        my_errstr(TBRD "Error:" TRST "could not open file\n");
        return NULL;
    }
    if (read(fd, content, st.st_size) == 0) {
        my_errstr(TBRD "Error:" TRST "invalid file\n");
        return NULL;
    }
    close(fd);
    return content;
}

int place_ship(char *map, char **tmp)
{
    static char ships[4] = {0, 0, 0, 0};
    int s;
    int p[2] = {0, 0};

    s = my_getnbr(*tmp);
    if (s < 2 || s > 5 || ships[s - 2])
        return 1;
    ships[s - 2] = 1;
    p[0] = strtop(tmp[1]);
    p[1] = strtop(tmp[2]);
    if (((p[0] & XPOS) != (p[1] & XPOS) && (p[0] & YPOS) != (p[1] & YPOS))
        || p[0] == -1 || p[1] == -1)
        return 1;
    return place_ship2(map, p, s);
}

void place_ships(char *map, char **arr)
{
    char **tmp;
    int err = 0;

    for (int i = 0; i < 4 && !err; i++) {
        tmp = my_str_sep(arr[i], ':');
        if (arrlen(tmp) != 3)
            err = 1;
        else
            err = place_ship(map, tmp);
        free(tmp);
    }
    if (err)
        *map = -1;
}

char *load_map(char const *filename)
{
    char *map = my_calloc(sizeof(char), 64);
    char *filecontent = read_file(filename);
    char **arr;

    if (filecontent == NULL)
        return NULL;
    arr = my_str_sep(filecontent, '\n');
    if (arrlen(arr) != 4 && arrlen(arr) != 5)
        return NULL;
    place_ships(map, arr);
    freearr(arr);
    free(filecontent);
    if (*map == -1)
        return NULL;
    return map;
}
