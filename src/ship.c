/*
** EPITECH PROJECT, 2019
** navy
** File description:
** ship
*/

#include "navy.h"

int postoidx(int p)
{
    return (p >> 16) + ((p & YPOS) << 3);
}

int place_ship2(char *map, int *p, int s)
{
    int sp = 0;
    int ep = 0;
    int offset = 0;

    if ((p[0] & XPOS) != (p[1] & XPOS)) {
        offset = (p[0] & XPOS) < (p[1] & XPOS) ? 1 : -1;
        if ((int)((p[1] & XPOS) - (p[0] & XPOS)) * offset != ((s - 1) << 16))
            return 1;
    } else {
        offset = (p[0] & YPOS) < (p[1] & XPOS) ? 8 : -8;
        if ((int)((p[1] & YPOS) - (p[0] & YPOS)) * offset / 8 != (s - 1))
            return 1;
    }
    sp = postoidx(p[0]);
    ep = postoidx(p[1]);
    for (int i = sp; i <= ep; i += offset)
        map[i] = s;
    return 0;
}
