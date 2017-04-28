/*
** usage.c for tetris in /home/tdebrand/PSU_2016_tetris
**
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
**
** Started on  Wed Feb 22 14:20:13 2017 Thomas DEBRAND PASSARD
** Last update Fri Mar 17 14:34:18 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "struct.h"
#include <stdlib.h>

void	usage(char *str, t_world *world, char c)
{
  my_putstr("Usage:  ");
  my_putstr(world->name);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("  --help\t\tDisplay this help\n");
  my_putstr("  -l --level={num}\tStart Tetris at level num (def: 1)\n");
  my_putstr("  -kl --key-left={K}\tMove the tetrimino LEFT using the K key ");
  my_putstr("(def: left arrow)\n");
  my_putstr("  -kr --key-right={K}\tMove the tetrimino RIGHT using the K key");
  my_putstr("(def: right arrow)\n");
  my_putstr("  -kt --key-turn={K}\tTURN the tetrimino clockwise 90d ");
  my_putstr("using the K key (def: top arrow)\n");
  my_putstr("  -kd --key-drop={K}\tDROP the tetrimino using the K key");
  my_putstr(" (def: down arrow)\n");
  my_putstr("  -kq --key-quit={K}\tQUIT the game using the K key");
  my_putstr(" (def: 'q' key)\n");
  my_putstr("  -kp --key-pause={K}\tPAUSE/RESTART the game using ");
  my_putstr("the K key (def: space bar)\n");
  my_putstr("  --map-size={row, col}\tSet the numbers of rows ");
  my_putstr("and columns of the map (def: 20,10)\n");
  my_putstr("  -w --without-next\tHide next tetrimino (def: false)\n");
  my_putstr("  -d --debug\t\tDebug mode (def: false)\n");
  exit (0);
}
