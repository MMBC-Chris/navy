/*
** EPITECH PROJECT, 2019
** navy
** File description:
** rcv attack
*/

#include "navy.h"

void atk_wait(int sig)
{
    int tmp = sigdone & 0xFFFF;

    tmp <<= 1;
    tmp += sig / 12;
    sigdone = (sigdone & 0xFFFF0000) + 0x10000 + tmp;
}

int send_result(pid_t enemy_pid, char *map, int atk_pos)
{
    my_putchar(atk_pos % 8 + 'A');
    my_putchar(atk_pos / 8 + '1');
    my_putstr(": ");
    usleep(1000);
    if (map[atk_pos] >= 2 && map[atk_pos] <= 5) {
        my_putstr("hit\n\n");
        kill(enemy_pid, 10);
        map[atk_pos] = 6;
    } else {
        my_putstr("missed\n\n");
        kill(enemy_pid, 12);
        map[atk_pos] = 7;
    }
    return 2 * check_win(map);
}

int wait_attack(pid_t enemy_pid, char *map)
{
    struct sigaction act;
    int atk_pos = 0;

    act.sa_handler = &atk_wait;
    sigaction(10, &act, NULL);
    sigaction(12, &act, NULL);
    my_putstr("waiting for enemy's attack...\n");
    sigdone = 0;
    while ((sigdone & 0xFFFF0000) != 0x60000);
    atk_pos = get_sigdone();
    atk_pos &= 0xFFFF;
    return send_result(enemy_pid, map, atk_pos);
}
