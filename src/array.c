/*
** EPITECH PROJECT, 2019
** navy
** File description:
** array
*/

#include "navy.h"

int arrlen(char **arr)
{
    int i;

    for (i = 0; arr[i] != NULL; i++);
    return i;
}

void freearr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}
