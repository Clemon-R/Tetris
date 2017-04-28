/*
** menu.h for tetris in /home/tdebrand/PSU_2016_tetris
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Mar 21 23:47:49 2017 Thomas DEBRAND PASSARD
** Last update Wed Mar 22 03:31:02 2017 Thomas DEBRAND PASSARD
*/

#ifndef MENU_WIN_H_
# define MENU_WIN_H_

# include <ncurses.h>
# include "struct.h"

void	print_theme1(t_world *, WINDOW *);
void	print_theme2(WINDOW *, t_world *);
void	theme_section(t_world *);
void	print_command(WINDOW *, t_world *);
void	print_menu(t_game, t_world *);
void	move_selected(WINDOW *, int *, char);
void	quit();
void	launch_game(t_game, t_world *);
char	themes(t_world *, char *);
void	command_gestion(WINDOW *, t_world *);
void	init_wincolor();

#endif
