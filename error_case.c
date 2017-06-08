/*
** error_case.c for error_case in /home/bouill_t/CODE/Piscine_C_bistromathique
** 
** Made by Thomas Bouillon
** Login   <bouill_t@epitech.net>
** 
** Started on  Sat Oct 31 14:23:36 2015 Thomas Bouillon
** Last update Sun Nov  1 15:32:37 2015 Robin Partouche
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"

int	check_strlen_compo(char *nb)
{
  int	i;

  i = 0;
  while (nb[i] != 0)
    {
      if (nb[i] >= '0' && nb[i] <= '9')
        i = i + 1;
      else
        {
          my_putstr(SYNTAXE_ERROR_MSG);
          exit(5);
        }
    }
  return (0);
}
