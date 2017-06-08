/*
** inf_div.c for inf_div in /home/murato_a/rendu/Piscine_C_bistromathique
** 
** Made by Valentin Muratore
** Login   <murato_a@epitech.net>
** 
** Started on  Fri Oct 30 10:55:42 2015 Valentin Muratore
** Last update Sat Oct 31 18:07:23 2015 Valentin Muratore
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"
#include "bistro.h"

char	*_init_result2(char *n1)
{
  char	*res;
  int	i;

  i = 0;
  res = malloc(sizeof(char) * (my_strlen(n1) + 1));
  while (i < my_strlen(n1))
    {
      res[i] = '0';
      i++;
    }
  res[i] = '\0';
  return (res);
}

char	*_init_r(char *str)
{
  char	*s;
  int	i;

  i = 0;
  s = malloc(my_strlen(str) + 1);
  while (i < my_strlen(str))
    {
      s[i] = str[i];
      i++;
    }
  s[i] = '\0';
  return (s);
}

char	*_div(char *n1, char *n2)
{
  char	*r;
  char	*q;

  r = _init_r(n1);
  q = _init_result2(n1);
  while (my_strcmp2(r, n2) >= 0)
    {
      r = less_inf(r, n2, 0, 0);
      q = add_inf(q, "1", 0, 0);
      r = correct_zero(r);
      q = correct_zero(q);
    }
  free(r);
  return (q);
}

char	*div_inf(char *n1, char *n2)
{
  int	less;

  less = 0;
  if (n1[0] == '-')
    n1 = del_less(n1, &less);
  if (n2[0] == '-')
    n2 = del_less(n2, &less);
  if (my_strlen(n2) == 1 && n2[0] == '1')
    {
      if (less != 1)
	return (n1);
      else
	return (add_less(n1));
    }
  else if (n2[0] == '0')
    exit (-12);
  else
    {
      if (less != 1)
	return (correct_zero(_div(n1, n2)));
      else
	return (add_less(correct_zero(_div(n1, n2))));
    }
}
