/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main header
*/

#ifndef _NAVY_H_
#define _NAVY_H_

#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#ifndef _SIGDONE_H_
extern int sigdone;
#endif

#define XPOS 0xFFFF0000
#define YPOS 0x0000FFFF

int my_usage(char const *);

int server(char const *);
int client(char const *, char const *);

int arrlen(char **);
void freearr(char **);

char *load_map(char const *);
int place_ship2(char *, int *, int);
void print_map(char const *);

int get_sigdone(void);

int strtop(char const *);
int postoidx(int);

int navy(char *, pid_t, int);
int attack_enemy(pid_t, char *);
int wait_attack(pid_t, char *);
int check_win(char *);

#endif
