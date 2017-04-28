/*
** struct.h for exam in /home/raphael.goulmot/rendu/PSU_2016_tetris
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Wed Mar  1 18:26:43 2017 Raphaël Goulmot
** Last update Wed Mar 22 03:22:58 2017 Raphaël Goulmot
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct  s_shape
{
  int   width;
  int   height;
  int   color;
  char  **data;
}               t_shape;

typedef struct  s_world
{
  t_shape       *shapes[1024];
  char	*key[6];
  char	*enter;
  char	next;
  char	level;
  int	theme;
  int	size[2];
  int	screen[2];
  char	debug;
  char	pause;
  char	*name;
}               t_world;

typedef struct	s_game
{
  int		level;
  int		score[2];
  int		lines;
  long		time;
  t_shape	*next;
  int			pos[2];
  //  int			posx;
  t_shape	*current;
  char		**map;
}		t_game;

#endif
