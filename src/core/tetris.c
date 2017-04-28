/*
** tetris.c for tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Wed Feb 22 15:50:28 2017 Raphaël Goulmot
** Last update Wed Mar 22 03:35:13 2017 Raphaël Goulmot
*/

#include "graphic.h"
#include "utils.h"
#include "shape.h"
#include "tetris.h"
#include "params.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <term.h>
#include <ncurses/curses.h>
#include <unistd.h>

char    *get_var(char **env, char *name)
{
  int   i;
  char  find;
  int   w;

  i = 0;
  find = 0;
  while (env[i] && !find)
    {
      w = 0;
      find = 1;
      while (name[w++])
	if (name[w - 1] != env[i][w - 1])
	  find = 0;
      i++;
    }
  if (find && my_strlen(env[i - 1]) > my_strlen(name) + 1)
    return (env[i - 1] + (my_strlen(name) + 1));
  else
    return (0);
}

void	init_world(t_world *world, char **env)
{
  char	*str;
  int		err;

  if (!env || !(str = get_var(env, "TERM")))
    {
      my_putstr_err("ERROR : TERM not found\n");
      exit (84);
    }
  setupterm(str, 1, &err);
  world->key[0] = tigetstr("kcuu1");
  world->key[1] = tigetstr("kcud1");
  world->key[2] = tigetstr("kcub1");
  world->key[3] = tigetstr("kcuf1");
  world->key[4] = "q";
  world->key[5] = " ";
  world->enter = tigetstr("cr");
  world->next = 0;
  world->level = 1;
  world->size[0] = 20;
  world->size[1] = 10;
  world->theme = 1;
  world->pause = 0;
  world->debug = 0;
}

void	debug_vars(t_world *world)
{
  my_putstr("*** DEBUG MODE ***\n");
  my_putstr("Key Left : ");
  my_putstr(world->key[2][0] == ' ' ? "(space)" : world->key[2]);
  my_putstr("\nKey Right : ");
  my_putstr(world->key[3][0] == ' ' ? "(space)" : world->key[3]);
  my_putstr("\nKey Turn : ");
  my_putstr(world->key[0][0] == ' ' ? "(space)" : world->key[0]);
  my_putstr("\nKey Drop : ");
  my_putstr(world->key[1][0] == ' ' ? "(space)" : world->key[1]);
  my_putstr("\nKey Quit : ");
  my_putstr(world->key[4][0] == ' ' ? "(space)" : world->key[4]);
  my_putstr("\nKey Pause : ");
  my_putstr(world->key[5][0] == ' ' ? "(space)" : world->key[5]);
  my_putstr("\nNext : ");
  my_putstr(world->next ? "No" : "Yes");
  my_putstr("\nLevel : ");
  my_put_nbr(world->level);
  my_putstr("\nSize : ");
  my_put_nbr(world->size[0]);
  my_putchar('*');
  my_put_nbr(world->size[1]);
  my_putchar('\n');
}

void	tetris(char **argv, int argc, char **env)
{
  t_world	world;
  int		i;
  char	key[1024];

  i = 0;
  init_world(&world, env);
  parse_commands(argc, argv, &world);
  if (world.debug)
    debug_vars(&world);
  load_tetrimino(&world);
  if (world.debug)
    {
      my_putstr("Press any key to start Tetris\n");
      while (my_strlen(read_keys(key)) <= 0);
    }
  load_tetris(&world);
  while (world.shapes[i++])
    free(world.shapes[i - 1]);
}
