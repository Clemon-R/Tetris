/*
** params.h for tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Thu Mar  2 09:56:24 2017 Raphaël Goulmot
** Last update Thu Mar 16 18:33:16 2017 Raphaël Goulmot
*/

#ifndef PARAMS_H_
# define PARAMS_H_

# include "struct.h"

void	parse_commands(int, char **, t_world *);
char	*get_value(char **, int);
void	exec_all_params(char **, int, t_world *);

#endif
