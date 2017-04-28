/*
** graphic.h for PSU_2016_tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris/include
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Tue Mar 14 10:40:54 2017 Raphaël Goulmot
** Last update Wed Mar 22 01:16:49 2017 Thomas DEBRAND PASSARD
*/

#ifndef	GRAPHIC_H_
# define GRAPHIC_H_

# include "struct.h"
# include <ncurses.h>

void	load_tetris(t_world *);
void	init_game(t_world *, t_game *);
void	new_next(t_game *, t_world *);
char	end_game(t_game, t_world *);
void	handle_key(t_game *, t_world *, WINDOW *);

#endif
