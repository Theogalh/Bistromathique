/*
** eval_expr.c for  in /home/partou_a/rendu/Piscine_C_bistromathique
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Sun Nov  1 15:25:05 2015 Robin Partouche
** Last update Sun Nov  1 16:30:54 2015 Thomas Bouillon
*/

#include <stdlib.h>
#include "mylist.h"
#include "my.h"
#include "bistromathique.h"

char	*calc_op(char *x, char *y, char operator, char *str)
{
  char	*tmp;

  tmp = xmalloc(my_strlen(str) * sizeof(char));
  if (operator == '+')
    tmp = (add_inf(x, y, 0, 0));
  else if (operator == '-')
    tmp = (less_inf(x, y, 0, 0));
  else if (operator == '*')
    tmp = (inf_mul(x, y));
  else if (operator == '/')
    tmp = (div_inf(x, y));
  else if (operator == '%')
    tmp = (mod_inf(x, y));
  else
    {
      write(2, "Error: No operator.", 20);
      exit(-2);
    }
  return (tmp);
}

int	validate_nbr(int j, char *x, struct s_list **pile)
{
  x = my_catch_in_list(pile);
  x[j] = '\0';
  my_put_in_list(pile, x);
  return (0);
}

int	calc_expr(int i, int j, char *str, struct s_list **pile)
{
  char		*y;
  char		*x;

  x = xmalloc(my_strlen(str) * sizeof(char));
  y = xmalloc(my_strlen(str) * sizeof(char));
  if (str[i] == OP_SPACE && (str[i - 1] >= 48 && str[i - 1] <= 57))
    return (validate_nbr(j, x, pile));
  else if ((str[i] >= 48 && str[i] <= 57) ||
	   str[i] == '-' && (str[i + 1] >= 48 && str[i + 1] <= 57))
    {
      if (j != 0)
        x = my_catch_in_list(pile);
      x[j] = str[i];
      my_put_in_list(pile, x);
      return (j + 1);
    }
  else if ((str[i] == '*' || str[i] == '+' ||str[i] == '-'
	    || str[i] == '/' || str[i] == '%'))
    {
      double_catch(&x, &y, pile);
      my_put_in_list(pile, calc_op(y, x, str[i], str));
      return (j);
    }
  else
    return (j);
}

char		*eval_expr(char *str)
{
  int		i;
  int		j;
  struct s_list	*pile;

  i = 0;
  j = 0;
  pile = NULL;
  while (str[i] != 0)
    {
      j = calc_expr(i, j, str, &pile);
      i = i + 1;
    }
  return (my_catch_in_list(&pile));
}

char	*del_zero(char *str)
{
  int	i;

  while (str[0] == '0' && str[1] != '\0')
    {
      i = 0;
      while (str[i + 1] != '\0')
	{
	  str[i] = str[i + 1];
	  i = i + 1;
	}
      str[i] = '\0';
    }
  return (str);
}
