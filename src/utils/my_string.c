/*
** my_string.c for default in /home/raphael.goulmot/rendu/PSU_2016_tetris
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed Feb 22 14:25:53 2017 Raphaël Goulmot
** Last update Thu Mar  2 09:24:41 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <stdlib.h>

char	**split(char *str, char c)
{
  int	i;
  int	n;
  int	w;
  char	**new;

  i = 0;
  n = 0;
  new = malloc(sizeof(char *) * (my_strlen(str) + 1));
  while (str[i])
    {
      if ((i == 0 && str[i] != c) || (i > 0 && str[i] != c && str[i - 1] == c))
	{
	  if (n > 0)
	    new[n - 1][w] = '\0';
	  w = 0;
	  new[n++] = malloc(sizeof(char) * (my_strlen(str) + 1));
	}
      if (str[i] != c)
	new[n - 1][w++] = str[i];
      i++;
    }
  if (n > 0)
    new[n - 1][w] = '\0';
  new[n] = '\0';
  return (new);
}

char	*stick_string(char *str1, char *str2)
{
  char	*new;
  int	i;
  int	n;

  n = 0;
  new = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
  i = 0;
  while (str1[i++])
    new[n++] = str1[i - 1];
  i = 0;
  while (str2[i++])
    new[n++] = str2[i - 1];
  new[n] = '\0';
  return (new);
}

char	find_extension(char *str, char *ext)
{
  int	i;
  int	e;

  i = my_strlen(str) - my_strlen(ext);
  if (i < 0)
    return (0);
  e = 0;
  while (str[i++] && ext[e++])
    {
      if (str[i - 1] != ext[e - 1])
	return (0);
    }
  return (1);
}

char	equals(char *str1, char *str2)
{
  int	i;

  i = 0;
  while ((str1[i] || str2[i]) && ++i)
    if (str1[i - 1] != str2[i - 1])
      return (0);
  return (1);
}
