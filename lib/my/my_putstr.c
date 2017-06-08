/*
** my_putstr.c for  in /home/partou_a/rendu/Piscine_C_J04
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Thu Oct  1 16:50:33 2015 Robin Partouche
** Last update Thu Oct  1 20:39:56 2015 Robin Partouche
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
