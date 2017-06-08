/*
** check_echo.c for check_echo in /home/bouill_t/git/Piscine_C_bistromathique
** 
** Made by Thomas Bouillon
** Login   <bouill_t@epitech.net>
** 
** Started on  Wed Oct 28 08:09:37 2015 Thomas Bouillon
** Last update Sun Nov  1 16:33:39 2015 Thomas Bouillon
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

void	check_echo_parenthese(char *echoint)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (echoint[i] != 0)
    {
      if (echoint[i] == ')' && j == 0)
	{
	  my_putstr(SYNTAXE_ERROR_MSG);
	  exit(17);
	}
      if (echoint[i] == '(')
	j = j + 1;
      if (echoint[i] == ')')
	j = j - 1;
      i = i + 1;
    }
  if (j != 0)
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      exit(17);
    }
}

int	check_echo_compo(char *echoint, char *reference)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (echoint[i] != 0)
    {
      if (echoint[i] != reference[j])
	j = j + 1;
      if (echoint[i] == reference[j])
	{
	  i = i + 1;
	  j = 0;
	}
      if (reference[j] == 0)
	{
	  my_putstr(SYNTAXE_ERROR_MSG);
	  exit(18);
	}
    }
}

int	check_echo_doublon(char *echoint, int i, char *reference)
{
  int	j;

  j = 12;
  while (reference[j] != 0)
    {
      if (echoint[i] != j)
	j = j + 1;
      if (echoint[i] == reference[j])
	{
	  j = 12;
	  while (reference[j] != 0)
	    {
	      if (echoint[i + 1] != reference[j])
		j = j + 1;
	      if (echoint[i + 1] == reference[j])
		{
		  my_putstr(SYNTAXE_ERROR_MSG);
		  exit(18);
		}
	    }
	}
    }
  return (0);
}

int	check_echo(char *echoint, char *reference)
{
  int	i;

  check_echo_parenthese(echoint);
  check_echo_compo(echoint, reference);
  i = 0;
  while (echoint[i] != 0)
    {
      if (echoint[i] != 0)
	check_echo_doublon(echoint, i, reference);
      i = i + 1;
    }
  return (0);
}
