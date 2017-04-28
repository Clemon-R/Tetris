/*
** controls.c for PSU_2016_tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris/src/core
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Sun Mar 19 21:33:31 2017 Raphaël Goulmot
** Last update Sun Mar 19 21:55:36 2017 Raphaël Goulmot
*/

#include <ncurses.h>
#include "struct.h"
#include "game.h"

void	move_x(t_world *world, t_game *game, char dir)
{
  if (dir)
    game->pos[0] += dir == 1 ? 1 : -1;
}
