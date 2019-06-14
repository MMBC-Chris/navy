/*
** EPITECH PROJECT, 2019
** navy
** File description:
** attack
*/

#include "navy.h"

void hit_wait(int sig)
{
    if (sig == 10)
        sigdone = 1;
    if (sig == 12)
        sigdone = 2;
}

int check_hit(pid_t enemy_pid, char *enemy_map, int pos)
{
    struct sigaction act;
    int hom = 0;

    act.sa_handler = &hit_wait;
    sigaction(10, &act, NULL);
    sigaction(12, &act, NULL);
    while (!sigdone);
    hom = get_sigdone();
    if (hom == 1) {
        my_putstr("hit\n\n");
        enemy_map[pos] = 6;
    } else if (hom == 2) {
        my_putstr("missed\n\n");
        enemy_map[pos] = 7;
    }
    return check_win(enemy_map);
}

int attack_enemy(pid_t enemy_pid, char *enemy_map)
{
    char *buf;
    int p = -1;

    do {
        my_putstr("attack: ");
        buf = get_next_line(0);
        p = strtop(buf);
        if (p == -1 || enemy_map[postoidx(p)]) {
            p = -1;
            my_putstr("wrong position\n");
        }
    } while (p == -1);
    my_printf("%s: ", buf);
    p = postoidx(p);
    for (int i = 5; i >= 0; i--) {
        usleep(1000);
        kill(enemy_pid, 10 + 2 * ((p >> i) & 0x1));
    }
    return check_hit(enemy_pid, enemy_map, p);
}
