/*
** mylist.h for  in /home/partou_a/rendu/Piscine_C_J11/include
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Mon Oct 12 13:40:45 2015 Robin Partouche
** Last update Wed Oct 14 09:56:15 2015 Robin Partouche
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

#endif /* !MYLIST_H_ */
