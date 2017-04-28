/*
** print.h for  in /home/tdebrand/PSU_2016_tetris
**
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
**
** Started on  Thu Mar 16 17:28:05 2017 Thomas DEBRAND PASSARD
** Last update Fri Mar 17 14:59:37 2017 Raphaël Goulmot
*/

#ifndef PRINT_H_
# define PRINT_H_

# include "struct.h"
# include <ncurses.h>

void	init_garphic(WINDOW **, WINDOW **, WINDOW **, WINDOW **);
WINDOW	*print_game(t_game, t_world);

#endif
