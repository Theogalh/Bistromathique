/*
** check_doublon.c for check_doublon in /home/bouill_t/CODE/Piscine_C_bistromathique
** 
** Made by Thomas Bouillon
** Login   <bouill_t@epitech.net>
** 
** Started on  Sat Oct 31 14:31:56 2015 Thomas Bouillon
** Last update Sun Nov  1 15:35:06 2015 Robin Partouche
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"
#include "bistromathique.h"
#include "mylist.h"

int     check_doublon1(char *base, char *operator)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (i < 7)
    {
      j = i;
      while (base[j] != 0)
        {
          if (base[j] == operator[i])
            {
              my_putstr(SYNTAXE_ERROR_MSG);
              exit(-2);
            }
          j = j + 1;
        }
      i = i + 1;
    }
  return (0);
}

int     check_doublon2(char *str1)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str1[i] != '\0')
    {
      j = i;
      while (str1[j] != 0)
        {
          if (str1[j + 1] == str1[i] )
            {
              my_putstr(SYNTAXE_ERROR_MSG);
              exit(-3);
            }
          else
            j = j + 1;
        }
      i = i + 1;
    }
  return (0);
}

char    *check_doublon(char *base, char *operator)
{
  check_doublon1(base, operator);
  check_doublon2(operator);
  check_doublon2(base);
  return (add_opandbase(base, operator));
}
