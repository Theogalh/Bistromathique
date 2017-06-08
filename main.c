/*
** main.c for  in /home/partou_a/rendu/Piscine_C_bistromatique
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Thu Oct 22 13:49:11 2015 Robin Partouche
** Last update Sun Nov  1 20:53:47 2015 Robin Partouche
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromathique.h"
#include "my.h"
#include "mylist.h"

int		main(int ac, char **av)
{
  char		*expr;
  unsigned int	size;

  if (ac != 4)
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" base ops\"()+-*//*%\" exp_len\n");
      return (1);
    }
  check_base(av[1]);
  check_ops(av[2]);
  size = my_getnbr(av[3]);
  expr = get_expr(size);
  bistromathique(av[1], av[2], av[3], expr);
  return (0);
}

static void	check_base(char *b)
{
  if (my_strlen(b) < 2)
    {
      my_putstr("Bad base\n");
      exit(1);
    }
}

static char	*get_expr(unsigned int size)
{
  char		*expr;

  if (size <= 0)
    {
      my_putstr("Bad expr len\n");
      exit(2);
    }
  expr = malloc(size+1);
  if (expr == 0)
    {
      my_putstr("could not alloc\n");
      exit(3);
    }
  if (read(0, expr, size) != size)
    {
      my_putstr("could not read\n");
      exit(4);
    }
  expr[size] = 0;
  return (expr);
}

static void	check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
    {
      my_putstr("Bad ops\n");
      exit(5);
    }
}
