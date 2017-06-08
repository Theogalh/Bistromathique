##
## Makefile for  in /home/partou_a/rendu/Piscine_C_J10/lib/my
## 
## Made by Robin Partouche
## Login   <partou_a@epitech.net>
## 
## Started on  Fri Oct  9 11:21:51 2015 Robin Partouche
## Last update Sat Oct 31 14:43:58 2015 Robin Partouche
##

SRC	=	my_8r1.c \
		my_aff_alpha.c \
		my_aff_chiffre.c \
		my_aff_comb2.c \
		my_aff_comb.c \
		my_aff_revalpha.c \
		my_evil_str.c \
		my_factorielle_rec.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_power_rec.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_show_wordtab.c \
		my_square_root.c \
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
		my_str_to_wordtab.c \
		my_strupcase.c \
		my_swap.c \
		sapin.c \
		sum_params.c \
		my_put_in_list.c \
		my_show_list.c \
		my_catch_in_list.c \
		my_strcmp2.c

NAME	= 	libmy.a

OBJ	= 	$(SRC:.c=.o)

HEAD	= 	my.h \
		mylist.h \
		bistro.h \
		bistromathique.h

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ../
	cp $(HEAD) ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
