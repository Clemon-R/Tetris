/*
** my_putstr.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Tue Nov 29 16:08:09 2016 Raphaël Goulmot
** Last update Fri Mar 17 15:34:50 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <unistd.h>
#include "struct.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i++])
    if (str[i - 1] == 27)
	my_putstr("^E");
      else
	my_putchar(str[i - 1]);
}

void	my_puttiget(char *str)
{
  int	i;

  i = 0;
  while (str[i++])
		my_putchar(str[i - 1]);
}

void	my_putstrd(char *str, t_world *world)
{
  if (world->debug)
    write(1, str, my_strlen(str));
}
