/*
** game.h for PSU_2016_tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris/include
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Fri Mar 17 14:54:19 2017 Raphaël Goulmot
** Last update Tue Mar 21 22:45:53 2017 Raphaël Goulmot
*/

#ifndef GAME_H_
# define GAME_H_

# include "struct.h"
# include <ncurses.h>

void	process_game(t_game *, t_world *, WINDOW *);
void	down_current(t_game *, t_world *);
char	check_next_place(t_game *, t_world *);
char	check_side_place(t_game *, t_world *, char);
void	display_map(t_game *, t_world *, WINDOW *);
void	init_current(t_game *, t_world *);

#endif
