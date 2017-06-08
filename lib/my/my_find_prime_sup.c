
/*
** my_find_prime_sup.c for  in /home/partou_a/rendu/Piscine_C_J05
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Mon Oct  5 20:20:43 2015 Robin Partouche
** Last update Wed Oct 14 09:09:37 2015 Robin Partouche
*/

int	my_is_prime2(int nb)
{
  int	i;

  if (nb == 1 || nb == 0)
    {
      return (0);
    }
  else if (nb == 2)
    {
      return (1);
    }
  i = 2;
  while (i != nb)
    {
      if (nb % i == 0)
        {
          return (0);
        }
      i = i + 1;
    }
  return (1);
}

int	my_find_prime_sup(int nb)
{
  if ((my_is_prime2(nb)) == 1)
    {
      return (nb);
    }
  else
    {
      my_find_prime_sup(nb + 1);
    }
}
