/*
** sapin.c for  in /home/partou_a/rendu/Piscine_C_Sapin
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Fri Oct  2 17:53:15 2015 Robin Partouche
** Last update Sun Nov  1 15:26:45 2015 Robin Partouche
*/

int	recurspace(int recup, int i, int tail)
{
  if (recup == 1)
    {
      return (3);
    }
  else
    {
      if (((tail - recup + 3) % 2) == 0)
        {
          return (recurspace(recup - 1, i, tail) + (recup + 3 - i));
        }
      else
        {
	  i = i + 1;
          return (recurspace(recup - 1, i, tail) + (recup + 3 - i));
        }
    }
}

int	recurlol(int recup, int j, int tail)
{
  if (recup == 1)
    {
      return (recurspace(tail, j, tail));
    }
  else
    {
      if (((tail - recup + 3) % 2) == 0)
        {
          return (recurlol(recup - 1, j, tail) -
		  ((recup / 2) + (recup % 2) + 1));
        }
      else
        {
          return (recurlol(recup - 1, j, tail) -
		  ((recup / 2) + (recup % 2) + 1));
        }
    }
}

int	branche(int tail, int recup, int star, int space)
{
  int	i;
  int	j;

  i = 0;
  while ((recup + 2) > (i - 1))
    {
      if (i == 0)
	{
	  star = recur(recup, tail);
	  j = 1;
	  space = recurlol(recup, j, tail);
	}
      else
	{
	  space = space - 1;
	  star = star + 2;
	}
      printsapin(space, star, 0);
      i = i + 1;
    }
}

void	sapin(int tail)
{
  int	recup;
  int	star;
  int	space;
  int	slash;

  recup = 1;
  while (recup != tail + 1)
    {
      branche(tail, recup, star, space);
      recup = recup + 1;
    }
  if ((tail % 2) == 0)
    {
      slash = tail + 1;
    }
  else
    {
      slash = tail;
    }
  space = (recur(tail, tail) + 2 * (tail + 2)) / 2 - (tail / 2);
  while (tail > 0)
    {
      printsapin(space, 0, slash);
      tail = tail - 1;
    }
}
