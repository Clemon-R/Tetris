/*
** shape.c for tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Wed Feb 22 15:02:42 2017 Raphaël Goulmot
** Last update Sun Mar 19 18:26:52 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "get_next_line.h"
#include "shape.h"
#include "tetris.h"
#include "debug.h"
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>

t_shape		*load_shape(int fid, t_shape *shape, t_world *world)
{
  int	y;
  char	*arg;
  int	max;

  max = 0;
  y = 0;
  if (!shape)
    return (0);
  shape->data = malloc(sizeof(char *) * (shape->height + 1));
  while ((arg = get_next_line(fid)))
    {
      if (my_strlen(arg) > max)
	max = my_strlen(arg);
      shape->data[y++] = arg;
    }
  shape->data[y] = 0;
  if (max != shape->width || my_strstrlen(shape->data) != shape->height)
    {
      my_putstr_errd(" : Error\n", world);
      free(shape);
      shape = 0;
    }
  else if (world->debug)
    debug_shape(shape);
  return (shape);
}

t_shape		*load_file(char *path, t_world *world)
{
  int		fid;
  char		*arg;
  char		**args;
  t_shape	*shape;

  path = stick_string("./tetriminos/", path);
  if ((fid = open(path, O_RDONLY)) < 0 || !(arg = get_next_line(fid)))
    {
      my_putstr_errd(" : Error\n", world);
      return (0);
    }
  args = split(arg, ' ');
  shape = malloc(sizeof(t_shape));
  if (my_strstrlen(args) != 3 || (shape->width = my_getnbr(args[0])) <= 0
      || (shape->height = my_getnbr(args[1])) <= 0
      || (shape->color = my_getnbr(args[2])) <= 0)
    {
      my_putstr_errd(" : Error\n", world);
      free(shape);
      shape = 0;
    }
  else if (world->debug)
    debug_size(shape);
  free(args);
  return (!shape ? 0 : load_shape(fid, shape, world));
}

void	count_files(int len, struct dirent **files)
{
  int	i;

  i = len;
  while (i--)
    if (!find_extension(files[i]->d_name, ".tetrimino"))
			len--;
  my_putstr("Tetriminos : ");
  my_put_nbr(len);
  my_putchar('\n');
}

void	load_tetrimino(t_world *world)
{
  struct dirent	**files;
  int	i;
  t_shape	*shape;
  int	len;
      int	index;

  if (!(i = 0) && (len = scandir("./tetriminos", &files, 0, alphasort)) <= 0)
    {
      my_putstr_err("ERROR : No such directory !\n");
      exit(84);
    }
  if (!(index = 0) && world->debug)
    count_files(len, files);
  while (index++ < len)
    {
      if (files[index - 1]->d_type == DT_REG
	  && find_extension(files[index - 1]->d_name, ".tetrimino"))
	{
	  my_putstrd("Tetriminos : Name ", world);
	  my_putstrd(split(files[index - 1]->d_name, '.')[0], world);
	  if ((shape = load_file(files[index - 1]->d_name, world)))
		  world->shapes[i++] = shape;
	}
    }
  world->shapes[i] = 0;
}
