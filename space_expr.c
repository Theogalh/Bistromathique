/*
** space_expr.c for space_expr in /home/bouill_t/git/Piscine_C_bistromathique
** 
** Made by Thomas Bouillon
** Login   <bouill_t@epitech.net>
** 
** Started on  Wed Oct 28 13:29:13 2015 Thomas Bouillon
** Last update Sun Nov  1 16:10:01 2015 Robin Partouche
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"

char	*correct_zero(char *echoint)
{
  int	i;

  while ((echoint[0] == '0' || (echoint[0] == '-' && echoint[1] == '0'))
	 && echoint[1] != '\0')
    {
      i = 0;
      while (echoint[i + 1] != '\0')
	{
	  echoint[i] = echoint[i + 1];
	  i = i + 1;
	}
      echoint[i] = '\0';
    }
  return (echoint);
}

char    *add_space_echo(char *echoint, char *operator, int i)
{
  int   j;
  int   h;
  char  *expr;

  h = 0;
  expr = malloc((my_strlen(echoint) * sizeof(char)) * 3);
  while (echoint[i] != '\0')
    {
      j = 0;
      while (echoint[i] != operator[j] && operator[j] != '\0')
	  j = j + 1;
      if (echoint[i] == operator[j] && echoint[i] != '\0')
        {
          expr[h] = ' ';
          expr[h + 1] = operator[j];
          expr[h + 2] = ' ';
          h = h + 2;
        }
      else
	  expr[h] = echoint[i];
      i = i + 1;
      h = h + 1;
    }
  expr[h] = '\0';
  return (expr);
}

void    double_catch(char **x, char **y, struct s_list **pile)
{
  *x = my_catch_in_list(pile);
  *y = my_catch_in_list(pile);
}
