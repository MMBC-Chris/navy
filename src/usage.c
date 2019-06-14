/*
** EPITECH PROJECT, 2019
** navy
** File description:
** usage
*/

#include "my.h"

int my_usage(char const *name)
{
    my_printf("USAGE\n\t%s [first_player_pid] navy_positions", name);
    my_printf("\nDESCRIPTION\n\tfirst_player_pid:  only for the 2nd");
    my_printf(" player.  pid of the first player.\n\tnavy_positions:");
    my_printf("  file representing the positions of the ships.\n");
    return 0;
}
