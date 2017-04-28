/*
** utils.h for default in /home/raphael.goulmot/default_struct
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Thu Dec 15 14:35:14 2016 Raphaël Goulmot
** Last update Fri Mar 17 14:44:58 2017 Raphaël Goulmot
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "struct.h"
# include <ncurses.h>

void	my_putchar(char);
void	my_putstr(char *);
void	my_puttiget(char *);
void	my_putstrd(char *, t_world *);
void	my_putstr_err(char *);
void	my_putstr_errd(char *, t_world *);
int	my_strlen(char *);
int	my_strstrlen(char **);
int	my_shapelen(t_shape **);
int	my_getnbr(char *);
void	my_put_nbr(int);
void	my_print_nbr(WINDOW *, int, int, int);
char	my_char_isnumeric(char);
char	my_str_isnumeric(char *);
char	my_char_isalpha(char);
char	equals(char *, char *);
char	find_extension(char *, char *);
char	*stick_string(char *, char *);
char	**split(char *, char);
int		my_rand(int, int);
long	get_timer();
char	*read_keys(char *);

#endif /* !UTILS_H_ */
