/*
** my_catch_in_list.c for  in /home/partou_a/rendu/Piscine_C_bistromatique/lib/my
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Fri Oct 23 12:23:47 2015 Robin Partouche
** Last update Sun Nov  1 15:24:41 2015 Robin Partouche
*/

#include <stdlib.h>
#include "mylist.h"

char		*my_catch_in_list(struct s_list **list)
{
  char		*nbr;
  struct s_list *elem;

  elem = *list;
  if (list == NULL || *list == NULL)
    {
      return (NULL);
    }
  if (list != NULL && *list != NULL)
    {
      nbr = elem->data;
      *list = elem->next;
      free(elem);
    }
  return (nbr);
}

void		*my_catch_char_in_list(struct s_list **list)
{
  void		*nbr;
  struct s_list *elem;

  elem = *list;
  if (list == NULL || *list == NULL)
    {
      return (NULL);
    }
  if (list != NULL && *list != NULL)
    {
      nbr = elem->data;
      *list = elem->next;
      free(elem);
    }
  return (nbr);
}
