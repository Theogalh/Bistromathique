/*
** bistro.h for bistro in /home/murato_a/rendu/multiinfi
** 
** Made by Valentin Muratore
** Login   <murato_a@epitech.net>
** 
** Started on  Mon Oct 19 14:16:26 2015 Valentin Muratore
** Last update Tue Oct 27 14:31:41 2015 Robin Partouche
*/

#ifndef BISTRO_H_
# define BISTRO_H_

typedef struct	s_number
{
  char		*str;
  unsigned int	length;
  unsigned int	idx;
}		t_number;

typedef struct	s_operation
{
  t_number	n1;
  t_number	n2;
  t_number	result;
  t_number	tmp;
}		t_operation;

#endif /* !BISTRO_H_ */
