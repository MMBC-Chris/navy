##
## EPITECH PROJECT, 2018
## Rush2
## File description:
## make lib
##

LIBSRC	=	my_calloc.c \
		my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_putchar.c \
		my_put_nbr_base.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_show_word_array.c \
		my_sort_int_array.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_strupcase.c \
		my_swap.c \
		my_itoa.c \
		ftostr.c \
		my_str_to_line_array.c \
		my_str_to_word_array.c \
		my_str_sep.c \
		clean_str.c \
		get_next_line.c
PSRC	=	my_printf.c \
		print_bin.c \
		print_formats.c \
		print_hex.c \
		print_str.c
CFLAGS	=	-Iinclude
LIBOBJ	=	$(LIBSRC:.c=.o)
POBJ	=	$(PSRC:.c=.o)
NAME	=	../libmy.a

all: $(NAME)

$(NAME): $(LIBOBJ) $(POBJ)
	ar rc $(NAME) $(LIBOBJ) $(POBJ)
	cp include/my.h ../../include/my.h

clean:
	rm -f $(LIBOBJ)
	rm -f $(POBJ)

fclean: clean
	rm -f libmy.a
	rm -f $(NAME)
	rm -f *.gc

re: fclean all
