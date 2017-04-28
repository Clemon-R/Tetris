/*
** my_strlen.c for default in /home/raphael.goulmot/default_struct
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Tue Dec 20 15:36:56 2016 Raphaël Goulmot
** Last update Thu Mar 16 19:09:41 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "struct.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] && ++i);
  return (i);
}

int	my_strstrlen(char **str)
{
  int	i;

  i = 0;
  while (str[i] && ++i);
  return (i);
}

int	my_shapelen(t_shape **str)
{
  int	i;

  i = 0;
  while (str[i] && ++i);
  return (i);
}
