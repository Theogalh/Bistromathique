##
## Makefile for  in /home/partou_a/rendu/Piscine_C_J10/lib/my
## 
## Made by Robin Partouche
## Login   <partou_a@epitech.net>
## 
## Started on  Fri Oct  9 11:21:51 2015 Robin Partouche
## Last update Sun Nov  1 16:43:15 2015 Robin Partouche
## Last update Sat Oct 31 17:18:36 2015 Robin Partouche
##

CC	=	gcc

SRC	=	eval_expr.c \
		nbr_to_eval_expr.c \
                nbr_to_eval_expr2.c \
		infadd.c \
		infadd2.c \
		infless.c \
		infless2.c \
		bistromathique.c \
		main.c \
		check_echo.c \
		error_case.c \
		space_expr.c \
		inf_mul.c \
		inf_div.c \
		inf_mul2.c \
		inf_mod.c \
		check_doublon.c \
		transform_op.c

NAME	= 	calc

LIBMAKED=	lib/my/libmy.a

LIBROAD	=	-L./lib/

LIB	=	-lmy

OBJ	=	eval_expr.o \
		nbr_to_eval_expr.o \
                nbr_to_eval_expr2.o \
		infadd.o \
		infadd2.o \
		infless.o \
		infless2.o \
                bistromathique.o \
                main.o \
                check_echo.o \
                error_case.o \
                space_expr.o \
		inf_mul.o \
		inf_div.o \
		inf_mul2.o \
		inf_mod.o \
		check_doublon.o \
		transform_op.o

LIBMAKE	=	lib/my

INCLUDE	=	-c -I./include/

FLAGS	+=	-W -Wextra -ansi -pedantic -g

LDFLAGS =

all: $(LIBMAKED) $(NAME)

$(LIBMAKED):
	make -C $(LIBMAKE)

$(NAME):
	$(CC) -c -g $(SRC) $(INCLUDE)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIBROAD) $(LIB) $(LDFLAGS)

clean:
	rm -f $(OBJ) && \
	make -C $(LIBMAKE) clean

fclean: clean
	rm -f $(NAME) && \
	rm -f $(LIBMAKED)

re: fclean all

.PHONY: all clean fclean re
