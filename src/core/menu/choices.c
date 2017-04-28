/*
** choices.c for tetris in /home/tdebrand/PSU_2016_tetris
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Wed Mar 22 01:10:31 2017 Thomas DEBRAND PASSARD
** Last update Wed Mar 22 03:47:25 2017 Thomas DEBRAND PASSARD
*/

#include "utils.h"
#include "menu.h"
#include "struct.h"
#include "game.h"
#include "print.h"
#include "graphic.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

void	quit()
{
  endwin();
  exit(0);
}

void    launch_game(t_game game, t_world *world)
{
  long  last;
  char  check;
  WINDOW        *content;

  new_next(&game, world);
  while (!end_game(game, world) && !(check = 0))
    {
      last = get_timer();
      content = print_game(game, *world);
      process_game(&game, world, content);
      while (check++ < 10 / game.level)
        {
          usleep(100000);
          handle_key(&game, world, content);
        }
    }
  free(game.map);
  clear();
  endwin();
  my_putstr("La salope, elle ta niker !\n");
  exit(0);
}

char	themes(t_world *world, char *str)
{
  world->theme = str[0] == '&' ? 1 : 0;
  world->theme = equals(str, "é") ? 2 : world->theme;
  world->theme = str[0] == '"' ? 3 : world->theme;
  world->theme = str[0] == '\'' ? 4 : world->theme;
  world->theme = str[0] == '(' ? 5 : world->theme;
  world->theme = str[0] == '-' ? 6 : world->theme;
  world->theme = equals(str, "è") ? 7 : world->theme;
  world->theme = str[0] == '_' ? 8 : world->theme;
  world->theme = equals(str, "ç") ? 9 : world->theme;
  return (world->theme);
}

void	print_command(WINDOW *command_win, t_world *world)
{
  char	key[124];

  wclear(command_win);
  box(command_win, 0, 0);
  mvwprintw(command_win, 1, 1, "LEFT : %s", world->key[2]);
  mvwprintw(command_win, 2, 1, "RIGHT : %s", world->key[3]);
  mvwprintw(command_win, 3, 1, "TURN : %s", world->key[0]);
  mvwprintw(command_win, 4, 1, "DROP : %s", world->key[1]);
  mvwprintw(command_win, 5, 1, "QUIT : %s", world->key[4]);
  mvwprintw(command_win, 6, 1, "PAUSE / RESTART : %s", world->key[5]);
  mvwprintw(command_win, 7, 1, "SIZE : %i * %i", world->size[0], world->size[1]);
  mvwprintw(command_win, 9, 1, "Press any key to exit the ");
  mvwprintw(command_win, 10, 1, "command menu");
  wrefresh(command_win);
  while (1)
    {
      if (my_strlen(read_keys(key)) > 0)
        return;
    }
}
