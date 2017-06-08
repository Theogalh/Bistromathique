/*
** infadd.c for infadd in /home/murato_a/rendu/Piscine_C_infinadd
** 
** Made by Valentin Muratore
** Login   <murato_a@epitech.net>
** 
** Started on  Tue Oct 20 14:44:55 2015 Valentin Muratore
** Last update Sat Oct 31 17:49:18 2015 Valentin Muratore
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

char	*boucle(char *n1, char *n2, char *res, int retenue)
{
  int	i;

  i = 1;
  while (my_strlen(n1) - i >= 0 || my_strlen(n2) - i >= 0)
    {
      if ((my_strlen(n1) - i) >= 0 && (my_strlen(n2) - i) >= 0)
	res[my_strlen(res) - i] = n1[my_strlen(n1) - i] +
	  n2[my_strlen(n2) - i] + retenue - 48;
      else if (my_strlen(n2) - i >= 0)
	res[my_strlen(res) - i] = n2[my_strlen(n2) - i] + retenue;
      else if (my_strlen(n1) - i >= 0)
	res[my_strlen(res) - i] = n1[my_strlen(n1) - i] + retenue;
      if (res[my_strlen(res) - i] > '9')
	{
	  retenue = 1;
	  res[my_strlen(res) - i] = res[my_strlen(res) - i] - 10;
	}
      else
	retenue = 0;
      i++;
    }
  if (retenue == 1)
    res[0] = retenue + 48;
  return (res);
}

char	*boucle_neg(char *n1, char *n2, char *res, int retenue)
{
  int	i;

  i = 1;
  while (my_strlen(n1) - i >= 0 || my_strlen(n2) - i >= 0)
    {
      if (my_strlen(n1) - i >= 0 && my_strlen(n2) - i >= 0)
	res[my_strlen(res) - i] = n1[my_strlen(n1) - i] -
	  n2[my_strlen(n2) - i] - retenue + 48;
      else if (my_strlen(n2) - i >= 0)
	res[my_strlen(res) - i] = n2[my_strlen(n2) - i] - retenue;
      else if (my_strlen(n1) - i >= 0)
	res[my_strlen(res) - i] = n1[my_strlen(n1) - i] - retenue;
      if (res[my_strlen(res) - i] < '0')
	{
	  retenue = 1;
	  res[my_strlen(res) - i] = res[my_strlen(res) - i] + 10;
	}
      else
	retenue = 0;
      i++;
    }
  if (retenue == 1)
    res[0] = retenue + 48;
  return (res);
}

char	*_init_res(char *n1, char *n2)
{
  char	*res;
  int	i;
  int	resize;

  if (my_strlen(n1) > my_strlen(n2))
    {
      res = malloc(sizeof(my_strlen(n1)));
      resize = my_strlen(n1) + 1;
    }
  else
    {
      res = malloc(sizeof(my_strlen(n2)));
      resize = my_strlen(n2) + 1;
    }
  i = 0;
  while (i < resize)
    {
      res[i] = '0';
      i = i + 1;
    }
  res[i] = '\0';
  return (res);
}

char	*add_inf(char *n1, char *n2, int i, int j)
{
  int	less;

  if (n1[0] == '-')
    n1 = del_less(n1, &less);
  if (n2[0] == '-')
    n2 = del_less(n2, &less);
  if (less == 1)
    return (less_inf(n1, n2, 0, 0));
  else
    return (last_function(n1, n2));
}
