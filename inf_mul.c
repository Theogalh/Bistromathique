/*
** infinadd.c for infinadd in /home/murato_a/rendu/Piscine_C_infinadd
** 
** Made by Valentin Muratore
** Login   <murato_a@epitech.net>
** 
** Started on  Tue Oct 20 09:05:22 2015 Valentin Muratore
<<<<<<< HEAD
** Last update Sun Nov  1 15:47:06 2015 Valentin Muratore
=======
** Last update Sat Oct 31 18:28:02 2015 Robin Partouche
>>>>>>> 63ab27fcfcc828351d89920c8f4f9e98e30e531a
*/

#include <stdio.h>
#include <stdlib.h>
#include "bistro.h"
#include "bistromathique.h"

int	_init_result_and_tmp(t_operation *op)
{
  int	i;

  i = 0;
  op->tmp.length = op->n1.length + op->n2.length + 1;
  op->result.length = op->tmp.length;
  op->tmp.idx = op->tmp.length;
  op->result.idx = op->result.length;
  op->tmp.str = malloc(sizeof(char) * (op->tmp.length + 2));
  op->result.str = malloc(sizeof(char) * (op->result.length + 2));
  if (op->tmp.str == NULL || op->result.str == NULL)
    {
      free(op->tmp.str);
      free(op->result.str);
      return (1);
    }
  while (i < op->tmp.length)
    {
      op->tmp.str[i] = 0;
      op->result.str[i] = 0;
      i = i + 1;
    }
  op->tmp.str[i] = '\0';
  op->result.str[i] = '\0';
  return (0);
}

void	_multiply(t_operation *op)
{
  int	somme;
  int	retenue;

  retenue = 0;
  op->n1.idx = op->n1.length;
  while (op->n1.idx > 0)
    {
      somme = (op->n1.str[op->n1.idx - 1] *
	       op->n2.str[op->n2.idx - 1]) + retenue;
      op->tmp.str[op->tmp.idx - 1] = somme % 10;
      retenue = somme /  10;
      op->n1.idx--;
      op->tmp.idx--;
    }
  while (op->tmp.idx > 0)
    {
      op->tmp.str[op->tmp.idx - 1] = retenue;
      retenue = 0;
      op->tmp.idx--;
    }
}

void	_add_tmp_to_result(t_operation *op)
{
  int	somme;
  int	retenue;

  retenue = 0;
  op->result.idx = op->result.length;
  op->tmp.idx = op->tmp.length;
  while (op->result.idx > 0 && op->tmp.idx > 0)
    {
      somme = op->tmp.str[op->tmp.idx - 1] +
	op->result.str[op->result.idx - 1] + retenue;
      op->result.str[op->result.idx - 1] = somme % 10;
      retenue = somme / 10;
      op->result.idx--;
      op->tmp.idx--;
    }
}

void	_process_operation(t_operation *op)
{
  int	nb_zero;
  int	j;

  nb_zero = 0;
  while (op->n2.idx > 0)
    {
      op->tmp.idx = op->tmp.length;
      j = 0;
      while (j < nb_zero)
	{
	  op->tmp.str[op->tmp.idx - 1] = 0;
	  j++;
	  op->tmp.idx--;
	}
      _multiply(op);
      _add_tmp_to_result(op);
      op->n2.idx--;
      nb_zero++;
    }
}

char		*inf_mul(char *n1, char *n2)
{
  t_operation	op;
  int		less;

  less = 0;
  n1 = del_less(n1, &less);
  n2 = del_less(n2, &less);
  if (my_strlen(n1) < my_strlen(n2))
    {
      _init_number(&op.n1, n2);
      _init_number(&op.n2, n1);
    }
  else
    {
      _init_number(&op.n1, n1);
      _init_number(&op.n2, n2);
    }
  if (_init_result_and_tmp(&op) != 0)
    return (NULL);
  _process_operation(&op);
  free(op.tmp.str);
  ascii_nbr(&op);
  if (less == 1)
    return (add_less(correct_zero(op.result.str)));
  else
    return (correct_zero(op.result.str));
}
