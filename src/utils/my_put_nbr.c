/*
** my_put_nbr.c for minishell in /home/raphael.goulmot/rendu/Bootstrap_Minishell
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed Jan  4 09:40:53 2017 Raphaël Goulmot
** Last update Thu Mar 16 18:24:44 2017 Thomas DEBRAND PASSARD
*/

#include "utils.h"
#include <ncurses.h>

void	my_put_nbr(int nbr)
{
  int	value;

  value = 1;
  if (nbr == 0)
    {
      my_putchar('0');
      return;
    }
  else if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  while (value <= nbr)
    value *= 10;
  value /= 10;
  while (value > 0)
    {
      my_putchar(48 + (nbr / value) % 10);
      value /= 10;
    }
}

void    my_print_nbr(WINDOW *form, int x, int y, int nbr)
{
  int   value;
  char	c[2];
  int	i;

  value = 1;
  c[1] = 0;
  i = 0;
  if (nbr <= 0)
    {
      c[0] = nbr == 0 ? '0' : '-';
      mvwprintw(form, y, x + i++, c);
      if (nbr == 0)
	return;
    }
  nbr *= nbr < 0 ? -1 : 1;
  while (value <= nbr)
    value *= 10;
  value /= 10;
  while (value > 0)
    {
      c[0] = 48 + (nbr / value) % 10;
      mvwprintw(form, y, x + i++, c);
      value /= 10;
    }
}
