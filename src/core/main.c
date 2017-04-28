/*
** main.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Tue Nov 29 16:01:44 2016 Raphaël Goulmot
** Last update Fri Mar 17 15:37:23 2017 Raphaël Goulmot
*/

#include "tetris.h"
#include "stdlib.h"
#include "utils.h"
#include <ncurses.h>

int	main(int argc, char **argv, char **env)
{
  if (!env || my_strstrlen(env) == 0)
    {
      my_putstr_err("ERROR : No environment set\n");
      return (84);
    }
  tetris(argv, argc, env);
  endwin();
  return (0);
}
