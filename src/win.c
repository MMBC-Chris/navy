/*
** EPITECH PROJECT, 2019
** navy
** File description:
** win or lose
*/

#include "navy.h"

int check_win(char *map)
{
    int count = 0;

    for (int i = 0; i < 64; i++)
        if (map[i] == 6)
            count++;
    return count == 14 ? 1 : 0;
}
