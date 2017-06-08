/*
** my_put_nbr.c for  in /home/partou_a/rendu/Piscine_C_J03
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Wed Sep 30 15:42:04 2015 Robin Partouche
** Last update Wed Sep 30 19:04:53 2015 Robin Partouche
*/

int	my_put_nbr(int nb)
{
  if (nb <= 9 && nb >= 0)
    {
      my_putchar(nb + 48);
    }
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
          nb = nb * -1;
	}
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + 48);
    }
}
