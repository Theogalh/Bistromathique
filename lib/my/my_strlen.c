/*
** my_strlen.c for  in /home/partou_a/rendu/Piscine_C_J04
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Thu Oct  1 20:41:01 2015 Robin Partouche
** Last update Mon Oct 26 13:54:21 2015 Robin Partouche
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i = i + 1;
    }
  return (i);
}
