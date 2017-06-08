/*
** infadd.c for infadd in /home/murato_a/rendu/Piscine_C_infinadd
** 
** Made by Valentin Muratore
** Login   <murato_a@epitech.net>
** 
** Started on  Tue Oct 20 14:44:55 2015 Valentin Muratore
** Last update Sat Oct 31 15:54:49 2015 Valentin Muratore
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

char	*if_complicated(char *n1, char *n2, int i, int j)
{
  char	*res;

  res = _init_res(n1, n2);
  if (my_strcmp(n1, n2) > 0)
    return (boucle_neg(n1, n2, res, 0));
  else if (my_strcmp(n1, n2) < 0)
    return (boucle_neg(n2, n1, res, 0));
  else
    return (boucle_neg(n1, n2, res, 0));
}

char	*if_simple(char *n1, char *n2, int i, int j)
{
  char	*res;

  res = _init_res(n1, n2);
  if (my_strlen(n1) > my_strlen(n2))
    return (boucle_neg(n1, n2, res, 0));
  else if (my_strlen(n1) < my_strlen(n2))
    return (boucle_neg(n2, n1, res, 0));
  else
    return (if_complicated(n1, n2, i, j));
}

char	*last_function(char *n1, char *n2)
{
  char	*res;

  res = _init_res(n1, n2);
  return (boucle(n1, n2, res, 0));
}
