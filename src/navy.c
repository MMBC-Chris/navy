/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy
*/

#include "navy.h"

void print_map(char const *map)
{
    int index = 0;

    my_putstr(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            index = map[i * 8 + j];
            if (!index)
                my_putchar('.');
            else if (index > 5)
                my_putchar(index == 6 ? 'x' : 'o');
            else
                my_put_nbr(index);
            my_putchar(j < 7 ? ' ' : '\n');
        }
    }
}

void print_maps(char const *player, char const *enemy)
{
    my_putstr("my positions:\n");
    print_map(player);
    my_putstr("\nenemy's positions:\n");
    print_map(enemy);
    my_putchar('\n');
}

int print_win(char *map, char *enemy_map, int win)
{
    print_maps(map, enemy_map);
    if (win == 1) {
        my_putstr("I won\n\n");
        return 0;
    } else if (win == 2) {
        my_putstr("Enemy won\n\n");
        return 1;
    }
    return 0;
}

int navy(char *map, pid_t enemy_pid, int turn)
{
    char *enemy_map = my_calloc(sizeof(char), 64);
    int win = 0;

    while (!win) {
        print_maps(map, enemy_map);
        if (!turn) {
            win = attack_enemy(enemy_pid, enemy_map);
            if (!win)
                win = wait_attack(enemy_pid, map);
        } else {
            win = wait_attack(enemy_pid, map);
            if (!win)
                win = attack_enemy(enemy_pid, enemy_map);
        }
    }
    return print_win(map, enemy_map, win);
}
