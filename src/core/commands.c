/*
** commands.c for tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Thu Mar  2 09:52:27 2017 Raphaël Goulmot
** Last update Fri Mar 17 15:16:53 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "commands.h"
#include "struct.h"
#include "shape.h"
#include <stdlib.h>

void	map(char *arg, t_world *world, char useless)
{
  char	**args;
  int	width;
  int	height;

  args = split(arg, ',');
  if (my_strlen(arg) == 0 || my_strstrlen(args) != 2)
    {
      my_putstr_err("ERROR : Syntax error map size\n");
      exit (84);
    }
  else if ((width = my_getnbr(args[0])) <= 0
	    || (height = my_getnbr(args[1])) <= 0)
    {
      my_putstr_err("ERROR : not nice value\n");
      exit (84);
    }
  else if (world->size[0] == width && world->size[1] == height)
    {
      my_putstr_err("ERROR : Already set this size\n");
      exit (84);
    }
  world->size[0] = width;
  world->size[1] = height;
}

void	next(char *arg, t_world *world, char useless)
{
  if (world->next)
    {
      my_putstr_err("ERROR : Already set without next\n");
      exit (84);
    }
  world->next = 1;
}

void	level(char *arg, t_world *world, char useless)
{
  int	level;

  if (my_strlen(arg) == 0
      || !my_str_isnumeric(arg) || (level = my_getnbr(arg)) <= 0)
    {
      my_putstr_err("ERROR : You must enter a valid level\n");
      exit (84);
    }
  else if (level == world->level)
    {
      my_putstr_err("ERROR : You must choose another level\n");
      exit (84);
    }
  world->level = level;
}

void	debug(char *arg, t_world *world, char kind)
{
  if (world->debug)
    {
      my_putstr_err("ERROR : You have already set debug mode\n");
      exit (84);
    }
  world->debug = 1;
}

void	key_x(char *arg, t_world *world, char kind)
{
  char	**key;
  int	i;

  i = 0;
  if (my_strlen(arg) == 0)
    {
      my_putstr_err("ERROR : You must enter a sequence\n");
      exit (84);
    }
  while (i < 6)
    if (equals(world->key[i++], arg))
	{
	  my_putstr_err("ERROR : This sequences already use\n");
	  exit (84);
	}
  key = &world->key[kind];
  if (*key)
    *key = arg;
}
