/*
** my_show_list.c for  in /home/partou_a/rendu/Piscine_C_J11/ex_01
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Mon Oct 12 17:13:25 2015 Robin Partouche
** Last update Mon Oct 12 17:13:54 2015 Robin Partouche
*/

#include <stdlib.h>
#include "mylist.h"

void	my_show_list(struct s_list *list)
{
  struct s_list *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->data);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
