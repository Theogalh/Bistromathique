/*
** inf_mod.c for inf_mod in /home/murato_a/rendu/Piscine_C_bistromathique
** 
** Made by Valentin Muratore
** Login   <murato_a@epitech.net>
** 
** Started on  Fri Oct 30 16:00:50 2015 Valentin Muratore
** Last update Sat Oct 31 18:25:24 2015 Valentin Muratore
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"
#include "bistro.h"

char	*mod_inf(char *n1, char *n2)
{
  char	*res;
  char	*div;
  char	*mul;

  res = _init_result2(n2);
  div = _init_result2(n1);
  mul = _init_result2(n1);
  div = correct_zero(div_inf(n1, n2));
  mul = correct_zero(inf_mul(div, n2));
  res = less_inf(n1, mul, 0, 0);
  return (correct_zero(res));
}
