/*
** my_rand.c for  in /home/tdebrand/PSU_2016_tetris/src/utils
**
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
**
** Started on  Thu Mar 16 18:39:07 2017 Thomas DEBRAND PASSARD
** Last update Sun Mar 19 21:19:58 2017 Raphaël Goulmot
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "utils.h"
#include "get_next_line.h"

int	my_rand(int a, int b)
{
  return (rand() % (b - a + 1) + a);
}

long	get_timer()
{
  return (time(0));
}

char	*read_keys(char	*buff)
{
  struct termios	old;
  struct termios	new;
  int			opt;
  int			len;

  ioctl(0, TCGETS, &old);
  ioctl(0, TCGETS, &new);
  ioctl(0, FIONBIO, &new);
  new.c_lflag &= ~ICANON;
  ioctl(0, TCSETS, &new);
  len = read(0, buff, 1023);
  buff[len] = 0;
  ioctl(0, TCSETS, &old);
  return (buff);
}
