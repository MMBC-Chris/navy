/*
** EPITECH PROJECT, 2018
** GNL
** File description:
** h
*/

#ifndef _GET_NEXT_LINE_H_
#define _GET_NEXT_LINE_H_

#ifndef READ_SIZE
#define READ_SIZE 3
#endif

typedef struct
{
    char buf[READ_SIZE];
    int i;
    int s;
    int j;
    char *line;
} gnl_t;

#endif
