/*
** my_is.c for default in /home/raphael.goulmot/default_struct
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Feb 21 18:49:01 2017 Raphaël Goulmot
** Last update Wed Mar  1 20:19:01 2017 Raphaël Goulmot
*/

#include "utils.h"

char	my_char_isalpha(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char	my_char_isnumeric(char c)
{
  return ((c >= '0' && c <= '9') || c == '-');
}

char	my_str_isnumeric(char *str)
{
  int	i;

  i = 0;
  while (str[i++])
    if (!my_char_isnumeric(str[i - 1]))
      return (0);
  return (1);
}
