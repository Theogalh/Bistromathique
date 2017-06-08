/*
** bistromathique.c for bistromathique in /home/bouill_t/CODE/Piscine_C_bistromathique
** 
** Made by Thomas Bouillon
** Login   <bouill_t@epitech.net>
** 
** Started on  Sat Oct 31 14:33:06 2015 Thomas Bouillon
** Last update Sun Nov  1 21:07:21 2015 Robin Partouche
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"
#include "bistromathique.h"
#include "mylist.h"

int	first_char(char *echo, int i, char *operator)
{
  if (echo[i - 1] == operator[3])
    return (i - 1);
  else
    return (i);
}

int     first_base_char(char *echo, char *operator, char *base)
{
  int   i;
  int   j;
  int   k;

  i = 0;
  k = 0;
  j = 2;
  while (echo[i] != base[k])
    {
      if (echo[i] != operator[j] && echo[i] != base[k])
        {
          j = j + 1;
          k = k + 1;
        }
      if (echo[i] == operator[j])
        {
          i = i + 1;
          j = 2;
          k = 0;
        }
      if (echo[i] == base[k])
        return (first_char(echo, i, base));
    }
}

char    *add_opandbase(char *base, char *operator)
{
  char  *all;
  int   i;
  int   j;

  j = 0;
  all = malloc(sizeof(char) * 17 + 1);
  all = my_strcpy(all, base);
  i = (my_strlen(base) - 1);
  while (operator[j] != 0)
    {
      all[i + 1] = operator[j];
      i = i + 1;
      j = j + 1;
    }
  all[i + 1] = '\0';
  return (all);
}

void		bistromathique(char *base, char *operator, char *nbchar, char *echo)
{
  char		*baseandop;
  char		*echoint;
  char		*reference;
  char		*echofinal;
  unsigned int	index;

  echoint = malloc((my_getnbr(nbchar) * sizeof(char)) * 2);
  reference = malloc(18 * sizeof(char));
  reference = my_strcpy(reference, "0123456789()+-*/%");
  check_strlen_compo(nbchar);
  index = first_base_char(echo, operator, base);
  echoint = transform_op1(echo, index);
  baseandop = check_doublon(base, operator);
  check_echo(echoint, baseandop);
  echoint = transform_op2(baseandop, echoint, reference);
  check_echo(echoint, reference);
  echoint = add_space_echo(echoint, "+-*/%", 0);
  echoint = eval_expr(nbr_to_eval_expr(echoint));
  echoint = correct_zero(echoint);
  echofinal = transform_op2(reference, echoint, baseandop);
  my_putstr(echofinal);
  my_putchar('\n');
}
