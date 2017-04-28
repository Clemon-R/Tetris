/*
** my_purstr_err.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:05:07 2016 Raphaël Goulmot
** Last update Wed Mar  1 20:02:19 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <unistd.h>
#include "struct.h"

void	my_putstr_err(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_putstr_errd(char *str, t_world *world)
{
  if (world->debug)
    write(2, str, my_strlen(str));
}
