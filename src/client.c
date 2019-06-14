/*
** EPITECH PROJECT, 2019
** navy
** File description:
** client connection
*/

#include "navy.h"

int client(char const *s_pid, char const *positions)
{
    pid_t server_pid = my_getnbr(s_pid);
    char *map = load_map(positions);

    if (map == NULL)
        return 84;
    my_printf("my_pid: %d\n", getpid());
    if (!kill(server_pid, 10)) {
        my_printf("successfully connected\n\n");
        return navy(map, server_pid, 1);
    } else
        return 84;
}
