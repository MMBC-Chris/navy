/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "my.h"
#include "navy.h"

int main(int ac, char **av)
{
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return my_usage(av[0]);
    if (ac == 2)
        return server(av[1]);
    else if (ac == 3)
        return client(av[1], av[2]);
    else
        return 84;
}
