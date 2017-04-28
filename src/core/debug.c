/*
** debug.c for tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Thu Mar  2 09:31:37 2017 Raphaël Goulmot
** Last update Fri Mar 17 15:57:51 2017 Raphaël Goulmot
*/

#include "struct.h"
#include "utils.h"

void    debug_shape(t_shape *shape)
{
  int	y;

  my_putstr(" :\n");
  y = 0;
  while (shape->data[y++])
    {
      my_putstr(shape->data[y - 1]);
      my_putchar('\n');
    }
}

void    debug_size(t_shape *shape)
{
  my_putstr(" : Size ");
  my_put_nbr(shape->width);
  my_putchar('*');
  my_put_nbr(shape->height);
  my_putstr(" : Color ");
  my_put_nbr(shape->color);
}
