/*
** infadd.c for infadd in /home/murato_a/rendu/Piscine_C_infinadd
** 
** Made by Valentin Muratore
** Login   <murato_a@epitech.net>
** 
** Started on  Tue Oct 20 14:44:55 2015 Valentin Muratore
<<<<<<< HEAD
** Last update Sun Nov  1 15:32:14 2015 Robin Partouche
=======
** Last update Sat Oct 31 18:16:06 2015 Robin Partouche
>>>>>>> 63ab27fcfcc828351d89920c8f4f9e98e30e531a
*/

#include <stdlib.h>
#include "bistromathique.h"

char	*less_inf(char *n1, char *n2, int i, int j)
{
  int	less;

  less = 0;
  if (n1[0] == '-')
    n1 = del_less(n1, &less);
  if (n2[0] == '-')
    n2 = del_less(n2, &less);
  if (less == 1)
    return (if_simple2(n1, n2, i, j));
  else if (less != 1 && my_strcmp2(n1, n2) == -1)
    return (add_less(correct_zero(last_function2(n2, n1))));
  else
    return (last_function2(n1, n2));
}
