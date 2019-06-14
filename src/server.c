/*
** EPITECH PROJECT, 2019
** navy
** File description:
** server connection
*/

#include "sigdone.h"
#include "navy.h"

void server_wait(int sig, siginfo_t *s_info, void *ucontext)
{
    if (sig == 10) {
        my_printf("\nenemy connected\n\n");
        sigdone = s_info->si_pid;
    }
}

int server(char const *positions)
{
    pid_t client_pid;
    struct sigaction wait_connect;
    char *map = load_map(positions);

    if (map == NULL)
        return 84;
    my_printf("my_pid: %d\nwaiting for enemy connection...\n", getpid());
    wait_connect.sa_sigaction = &server_wait;
    wait_connect.sa_flags = SA_SIGINFO;
    sigaction(10, &wait_connect, NULL);
    while (!sigdone);
    client_pid = get_sigdone();
    return navy(map, client_pid, 0);
}
