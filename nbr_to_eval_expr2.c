/*
** nbr_to_eval_expr2.c for  in /home/partou_a/rendu/Piscine_C_bistromathique
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Sun Nov  1 16:36:01 2015 Robin Partouche
** Last update Sun Nov  1 20:53:05 2015 Robin Partouche
*/

#include <stdlib.h>
#include "mylist.h"
#include "my.h"
#include "bistromathique.h"

char	*put_operator(char x, char *str_list1, int *j, struct s_list **pile)
{
  while (x != '(' && *pile != NULL)
    {
      str_list1[*j] = ' ';
      str_list1[*j + 1] = x;
      *j = *j + 2;
      x = my_catch_char_in_list(pile);
    }
  x = my_catch_char_in_list(pile);
  while (x != '(' && *pile != NULL)
    {
      str_list1[*j] = ' ';
      str_list1[*j + 1] = x;
      *j = *j + 2;
      x = my_catch_char_in_list(pile);
    }
  j = j + 1;
  my_put_in_list(pile, x);
  return (str_list1);
}

char    verif_prio(char **str_list, int i, int *j, struct s_list **pile)
{
  if (str_list[0][i] == '-' || str_list[0][i] == '+' || str_list[0][i] == '/'
      || str_list[0][i] == '*' || str_list[0][i] == '%')
    my_put_in_list(pile, str_list[0][i]);
  else
    {
      my_put_in_list(pile, str_list[1][*j]);
      str_list[1][*j] = str_list[0][i];
    }
  return (str_list[1][*j]);
}

char	*unpile_all(char *str, struct s_list **pile, int *j)
{
  while (*pile != NULL)
    {
      str[*j] = ' ';
      str[*j + 1] = my_catch_char_in_list(pile);
      *j = *j + 2;
    }
  return (str);
}
