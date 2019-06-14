/*
** EPITECH PROJECT, 2019
** navy
** File description:
** sigdone management
*/

#include "navy.h"

int get_sigdone(void)
{
    int tmp = sigdone;

    sigdone = 0;
    return tmp;
}
