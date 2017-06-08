/*
** inf_mul2.c for inf_mul2 in /home/murato_a/rendu/Piscine_C_bistromathique
** 
** Made by Valentin Muratore
** Login   <murato_a@epitech.net>
** 
** Started on  Sat Oct 31 11:10:03 2015 Valentin Muratore
** Last update Sun Nov  1 16:01:07 2015 Valentin Muratore
*/

#include "bistromathique.h"
#include "bistro.h"

void	_init_number(t_number *n, char *str)
{
  int	i;

  i = 0;
  n->str = str;
  n->length = my_strlen(str);
  n->idx = n->length;
  while (i < n->length)
    {
      n->str[i] = n->str[i] - '0';
      i++;
    }
}

void	ascii_nbr(t_operation *op)
{
  int	i;

  i = 0;
  while (i < op->result.length)
    {
      op->result.str[i] += '0';
      i++;
    }
  i = 0;
  while (i < op->n1.length)
    {
      op->n1.str[i] += '0';
      i++;
    }
  i = 0;
  while (i < op->n2.length)
    {
      op->n2.str[i] += '0';
      i++;
    }
}

char	*bouclecpy(char	*str)
{
  char	*s;
  int	i;

  s = xmalloc(my_strlen(str));
  i = 0;
  while (str[i] != '\0')
    {
      s[i] = str[i];
      i = i + 1;
    }
  s[i] = '\0';
  return (s);
}

char	*del_less(char *str, int *less)
{
  char	*str2;
  int	i;

  if (str[0] == '-')
    {
      i = 0;
      str2 = xmalloc(my_strlen(str));
      while (str[i + 1] != '\0')
	{
	  str2[i] = str[i + 1];
	  i++;
	}
      str2[i] = '\0';
      *less = *less + 1;
      return (str2);
    }
  else
    {
      str2 = xmalloc(my_strlen(str));
      str2 = bouclecpy(str);
      return (str2);
    }
}
