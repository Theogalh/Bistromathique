/*
** transform_op.c for transform_op in /home/bouill_t/CODE/Piscine_C_bistromathique
** 
** Made by Thomas Bouillon
** Login   <bouill_t@epitech.net>
** 
** Started on  Sat Oct 31 14:22:25 2015 Thomas Bouillon
** Last update Sun Nov  1 15:31:45 2015 Robin Partouche
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"
#include "bistromathique.h"
#include "mylist.h"

char	*transform_op1(char *echo, unsigned int index)
{
  char  *echoint;
  int   i;

  i = 0;
  echoint = malloc(sizeof(char) * my_strlen(echo));
  while (echo[index] != 0)
    {
      echoint[i] = echo[index];
      i = i + 1;
      index = index + 1;
    }
  echoint[i + 1] = '\0';
  return (echoint);
}

char    *transform_op2(char *all, char *echo, char *reference)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (echo[i] != '\0')
    {
      if (echo[i] == all[j])
        {
          echo[i] = reference[j];
          i = i + 1;
          j = 0;
        }
      else
        j = j + 1;
    }
  return (echo);
}
