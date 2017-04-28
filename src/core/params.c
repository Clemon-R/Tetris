/*
** params.h for tetris in /home/raphael.goulmot/rendu/PSU_2016_tetris
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.eu>
**
** Started on  Thu Mar  2 09:54:34 2017 Raphaël Goulmot
** Last update Sun Mar 19 18:45:40 2017 Raphaël Goulmot
*/

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "struct.h"
#include "utils.h"
#include "usage.h"
#include "commands.h"

static void (* const list_ptsFunction[])(char *o, t_world *i, char p) = {
  &usage,
  &debug,
  &key_x,
  &level,
  &next,
  &map
};

static const struct	option long_options[] =
{
  {"help", no_argument, 0, 0},
  {"d", no_argument, 0, 1},
  {"debug", no_argument, 0, 1},
  {"kt", required_argument, 0, 2},
  {"key-turn", required_argument, 0, 2},
  {"kd", required_argument, 0, 3},
  {"key-drop", required_argument, 0, 3},
  {"kl", required_argument, 0, 4},
  {"key-left", required_argument, 0, 4},
  {"kr", required_argument, 0, 5},
  {"key-right", required_argument, 0, 5},
  {"kq", required_argument, 0, 6},
  {"key-quit", required_argument, 0, 6},
  {"kp", required_argument, 0, 7},
  {"key-pause", required_argument, 0, 7},
  {"l", required_argument, 0, 8},
  {"level", required_argument, 0, 8},
  {"w", no_argument, 0, 9},
  {"without-next", no_argument, 0, 9},
  {"max-size", required_argument, 0, 10},
  {0, 0, 0, 0}
};

char	check_params(char *str)
{
  int	i;

  if ((i = 0) || !str || my_strlen(str) < 2)
    return (0);
  else if (str[0] == '-' && str[1] != '-')
    while (str[i++])
	{
	  if (str[i - 1] == '=')
	    return (0);
	}
  return (1);
}

void	parse_commands(int argc, char **argv, t_world *world)
{
  int	i;
  int	opt;

  i = 0;
  world->name = argv[0];
  while ((opt = getopt_long_only(argc, argv, "", long_options, &i)) != -1)
	 {
      if (opt != '?' && check_params(argv[optind - 1]))
	{
	  if (opt >= 2 && opt <= 7)
	    (*list_ptsFunction[2])(optarg, world, opt - 2);
	  else
	    (*list_ptsFunction[opt > 7 ? opt - 5 : opt])(optarg, world, 0);
	}
      else
	exit (84);
    }
  if (optind < argc)
    {
      my_putstr_err("ERROR : Non-option elements : ");
      while (optind < argc && (argv[optind] = stick_string(argv[optind], " ")))
	my_putstr_err(argv[optind++]);
      my_putstr_err("\n");
      exit (84);
    }
}
