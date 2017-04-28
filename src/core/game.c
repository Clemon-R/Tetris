/*
** game.c for PSU_2016_tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris/src/core
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Fri Mar 17 14:54:08 2017 Raphaël Goulmot
** Last update Wed Mar 22 03:27:00 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "struct.h"
#include "graphic.h"
#include <ncurses.h>
#include <stdlib.h>

void	init_current(t_game *game, t_world *world)
{
  game->current = game->next;
  game->pos[0] = world->size[0] / 2 - game->current->width / 2;
  game->pos[1] = -game->current->height;
  new_next(game, world);
}

void	display_map(t_game *game, t_world *world, WINDOW *content)
{
  int	y;
  int	x;
  char	c[2];

  y = 0;
  c[1] = 0;
  wclear(content);
  box(content, ACS_VLINE, ACS_HLINE);
  while (game->map[y++])
    mvwprintw(content, y, 1, game->map[y - 1]);
  y = 0;
  while (game->current->data[y++] && !(x = 0))
    {
       if (game->pos[1] + (y - 1) >= 0)
	 while (game->current->data[y - 1][x++])
	   {
	     c[0] = game->current->data[y - 1][x - 1];
	     wattron(content, COLOR_PAIR(game->current->color));
	     if (c[0] != ' ')
	       mvwprintw(content, game->pos[1] + y, game->pos[0] + x , c);
	     wattroff(content, COLOR_PAIR(game->current->color));
	   }
    }
  wrefresh(content);
}

char	check_side_place(t_game *game, t_world *world, char dir)
{
  int	y;
  int	x;
  char	check;

  y = 0;
  while (game->current->data[y++])
    {
      check = -1;
      x = dir ? my_strlen(game->current->data[y - 1]) - 1 : 0;
      while (check == -1 && game->current->data[y - 1][x])
	{
	  if (game->current->data[y - 1][x] != ' ')
	    check = x;
	  x += dir ? -1 : 1;
	}
      if (check > -1 && game->pos[1] + (y - 1) >= 0
	  && game->pos[0] + check + (dir ? 1 : -1) < world->size[0]
	  && game->map[game->pos[1] + (y - 1)]
	  [game->pos[0] + check + (dir ? 1 : -1)] != ' ')
	return (0);
    }
  return (1);
}

char	check_next_place(t_game *game, t_world *world)
{
  int	y;
  int	x;

  if (game->pos[1] + game->current->height + 1 > world->size[1])
    return (0);
  y = 0;
  while (game->current->data[y++] && !(x = 0))
    while (game->current->data[y - 1][x++])
      if (game->pos[1] + y >= 0 && game->current->data[y - 1][x - 1] != ' '
	  && game->map[game->pos[1] + y][game->pos[0] + (x - 1)] != ' ')
	return (0);
  return (1);
}

void	down_current(t_game *game, t_world *world)
{
  int	y;
  int	x;

  if (!check_next_place(game, world))
    {
      if (game->pos[1] < 0)
	{
	  endwin();
	  my_putstr(my_rand(1, 2) == 1 ? "Tu pue la merde !!! Starfoullah..\n"
		    : "Mameneeeeee tété trés nulll...\n");
	  exit(0);
	  return;
	}
      y = 0;
      while (game->current->data[y++] && !(x = 0))
	while (game->current->data[y - 1][x++])
	  if (game->pos[1] + (y - 1) >= 0
	      && game->current->data[y - 1][x - 1] != ' ')
	    game->map[game->pos[1] + (y - 1)][game->pos[0] + (x - 1)] =
	    game->current->data[y - 1][x - 1];
      init_current(game, world);
    }
  else
    game->pos[1]++;
}

void	process_game(t_game *game, t_world *world, WINDOW *content)
{
  if (!game->current)
    init_current(game, world);
  down_current(game, world);
  if (!world->pause && COLS >= 31 + world->size[0])
    display_map(game, world, content);
  else if (world->pause)
    {
      clear();
      move(LINES / 2, COLS / 2 - 2);
      printw("Pause");
      refresh();
    }
  else
    {
      clear();
      move(0, 0);
      printw("You must resize de screen !");
      refresh();
    }
}
