/*
** EPITECH PROJECT, 2018
** Day07
** File description:
** Libmy header
*/

#ifndef __MY_LIB_INCLUDED
#define __MY_LIB_INCLUDED

#include <stddef.h>

#define TRST        "\x1B[0m"
#define TBBOLD      "\x1B[1m"
#define TBBLACK     "\x1B[90m"
#define TBRED       "\x1B[91m"
#define TBGREEN     "\x1B[92m"
#define TBYELLOW    "\x1B[93m"
#define TBBLUE      "\x1B[94m"
#define TBMAGENTA   "\x1B[95m"
#define TBCYAN      "\x1B[96m"
#define TBWHITE     "\x1B[97m"

#define TBRD TBRED

void *my_memset(void *, int, size_t);
void *my_calloc(size_t, size_t);
void my_putchar(char);
void my_errchar(char);
int my_isneg(int);
char *my_itoa(int);
int my_put_nbr(long);
int my_put_nbr_base(long, char const *);
int my_put_unbr_base(unsigned long, char const *);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_errstr(char const *);
int my_strlen(char const *);
int num_len(long);
int num_len_base(long, char const *);
int unum_len_base(unsigned long, char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_isprime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_printable(char const *);
int my_showstr(char const *);
int my_showmem(char const *);
int my_show_word_array(char * const *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char **my_str_to_word_array(char const *);
char **my_str_to_line_array(char const *);
char **my_str_sep(char const *, char);
char *my_strdup(char const *);
int my_printf(char const *, ...);
char *ftostr(char const *);
char *clean_str(char const *);
char *get_next_line(int);

#endif
