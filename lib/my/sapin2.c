/*
** sapin2.c for  in /home/partou_a/rendu/Piscine_C_J11/lib/my
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Wed Oct 14 09:51:05 2015 Robin Partouche
** Last update Wed Oct 14 09:51:21 2015 Robin Partouche
*/

int	printsapin(int space, int star, int slash)
{
  while (space > 0)
    {
      write(1, " ", 1);
      space = space - 1;
    }
  while (slash > 0)
    {
      write(1, "|", 1);
      slash = slash - 1;
    }
  while (star > 0)
    {
      write(1, "*", 1);
      star = star - 1;
    }
  write(1, "\n", 1);
}

int	recur(int recup, int tail)
{
  if (recup == 1)
    {
      return (1);
    }
  else
    {
      if ((recup % 2) == 0)
        {
          return (recur(recup - 1, tail) + recup + 2);
        }
      else
        {
          return (recur(recup - 1, tail) + recup + 3);
        }
    }
}
