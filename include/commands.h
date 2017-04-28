/*
** commands.h for tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Thu Mar  2 09:53:22 2017 Raphaël Goulmot
** Last update Mon Mar 13 18:35:27 2017 Raphaël Goulmot
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

# include "struct.h"

void	debug(char *, t_world *, char);
void	key_x(char *, t_world *, char);
void	level(char *, t_world *, char);
void	next(char *, t_world *, char);
void	map(char *, t_world *, char);

#endif
