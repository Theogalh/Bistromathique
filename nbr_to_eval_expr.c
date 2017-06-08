/*
** nbr_to_eval_expr.c for  in /home/partou_a/rendu/Piscine_C_bistromathique
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Tue Oct 27 11:43:38 2015 Robin Partouche
** Last update Sun Nov  1 20:51:10 2015 Robin Partouche
*/

#include <stdlib.h>
#include "mylist.h"
#include "my.h"
#include "bistromathique.h"

void	*xmalloc(int n)
{
  void	*new_malloc;

  if (((new_malloc = malloc(n)) == NULL) || n <= 0)
    {
      write(2, "Error: malloc", 14);
      exit(20);
    }
  return (new_malloc);
}

char	*correct_space(char *str)
{
  int	i;
  int	j;
  char	*str2;

  i = 0;
  j = 0;
  str2 = xmalloc((my_strlen(str) + 1) * sizeof(char));
  while (str[i] != 0)
    {
      if (str[i] == OP_SPACE && str[i + 1] == 0)
	  i = i + 1;
      else if (str[i] == OP_SPACE && str[i + 1] == OP_SPACE)
      {
	str2[j] = str[i];
	i = i + 1;
      }
      else
	{
	  str2[j] = str[i];
	}
      j = j + 1;
      i = i + 1;
    }
  str2[j] = '\0';
  return (str2);
}

char	*add_less(char *str)
{
  int	i;
  char	*str2;

  str2 = xmalloc((my_strlen(str) + 2) * sizeof(char));
  i = 0;
  while (str[i] != 0)
    {
      if (i == 0)
        {
          str2[0] = '-';
	  str2[1] = str[0];
        }
      else
        {
          str2[i + 1] = str[i];
        }
      i = i + 1;
    }
  str2[i + 1] = '\0';
  return (str2);
}

char	*calc_nbr_to_expr(int i, int *j, char **str_list, struct s_list **pile)
{
  char	x;

  x = my_catch_char_in_list(pile);
  if (str_list[0][i] == ')')
    return (put_operator(x, str_list[1], j, pile));
  else if (((str_list[0][i] < 48 || str_list[0][i] > 57) &&
	    (x == '(' || *pile == NULL || ((x == '-' || x == '+') &&
	    (str_list[0][i] == '*' || str_list[0][i] == '%' || str_list[0][i] == '/')))
	    || str_list[0][i] == '(') && str_list[0][i] != OP_SPACE)
    {
      my_put_in_list(pile, x);
      my_put_in_list(pile, str_list[0][i]);
      return (str_list[1]);
    }
  else
    {
      str_list[1][*j] = x;
      str_list[1][*j] = verif_prio(str_list, i, j, pile);
      *j = *j + 1;
    }
  return (str_list[1]);
}

char		*nbr_to_eval_expr(char *str)
{
  int		i;
  int		j;
  struct s_list	*pile;
  char		**str_list;
  char		*str2;

  str_list = xmalloc(2 * sizeof(char*));
  str2 = xmalloc((my_strlen(str) + 100) * sizeof(char));
  str_list[0] = str;
  str_list[1] = str2;
  i = 0;
  j = 0;
  pile = NULL;
  while (i < my_strlen(str))
    {
      str2 = calc_nbr_to_expr(i, &j, str_list, &pile);
      i = i + 1;
    }
  str2 = unpile_all(str2, &pile, &j);
  str2[j + 1] = '\0';
  return (correct_space(str2));
}
