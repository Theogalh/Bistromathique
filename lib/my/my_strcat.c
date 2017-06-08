/*
** my_strcat.c for  in /home/partou_a/rendu/Piscine_C_J07/ex_02
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Tue Oct  6 17:32:47 2015 Robin Partouche
** Last update Fri Oct 23 11:59:40 2015 Robin Partouche
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (dest[i] != '\0')
    {
      i = i + 1;
    }
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
