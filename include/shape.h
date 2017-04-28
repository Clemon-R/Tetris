/*
** shape.h for tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Wed Feb 22 15:52:15 2017 Raphaël Goulmot
** Last update Fri Mar 17 13:41:17 2017 Raphaël Goulmot
*/

#ifndef SHAPE_H_
# define SHAPE_H_

# include "struct.h"

t_shape	*load_shape(int, t_shape *, t_world *);
t_shape	*load_file(char *, t_world *);
void		load_tetrimino(t_world *);

#endif
