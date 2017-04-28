/*
** graphic.c for PSU_2016_tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris/src/core
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Tue Mar 14 10:39:01 2017 Raphaël Goulmot
** Last update Wed Mar 22 03:31:41 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "graphic.h"
#include "print.h"
#include "game.h"
#include "menu.h"
#include "controls.h"
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

void	init_game(t_world *world, t_game *game)
{
  int	y;
  int	x;

  game->level = world->level;
  game->score[0] = 0;
  game->score[1] = 0;
  game->lines = 0;
  game->map = malloc(sizeof(char *) * (world->size[1] + 1));
  y = 0;
  while (y++ < world->size[1] && !(x = 0))
    {
      game->map[y - 1] = malloc(sizeof(char) * (world->size[0] + 1));
      while (x < world->size[0] && ++x)
	game->map[y - 1][x - 1] = ' ';
      game->map[y - 1][x] = 0;
    }
  game->map[world->size[1]] = 0;
  game->time = get_timer();
  game->current = 0;
}

char	end_game(t_game game, t_world *world)
{
  int	y;
  int	x;
  char	check;

  x = 0;
  while (x < world->size[0])
    {
      y = 0;
      check = 0;
      while (!check && y < world->size[1])
	{
	  if (game.map[y][x] == ' ')
	    check = 1;
	  y++;
	}
      if (!check)
	return (1);
      x++;
    }
  return (0);
}

void	new_next(t_game *game, t_world *world)
{
  game->next = world->shapes[my_rand(0, my_shapelen(world->shapes) - 1)];
}

void	handle_key(t_game *game, t_world *world, WINDOW *content)
{
  char	key[1024];

  if (my_strlen(read_keys(key)) > 0)
    {
      if (equals(key, world->key[1]))
	down_current(game, world);
      else if (equals(key, world->key[3]))
	{
	  if (check_side_place(game, world, 1))
	    game->pos[0]++;
	}
      else if (equals(key, world->key[2]))
	{
	if (check_side_place(game, world, 0))
	  game->pos[0]--;
	}
      else if (equals(key, world->key[5]))
	  world->pause = !world->pause;
      (!world->pause ? display_map(game, world, content) : 0);
      key[0] = 0;
    }
}

void	load_tetris(t_world *world)
{
  t_game	game;

  srand(time(0));
  init_game(world, &game);
  my_puttiget(tigetstr("smkx"));
  initscr();
  curs_set(0);
  print_menu(game, world);
  free(game.map);
}
