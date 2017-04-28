/*
** main_menu.c for  in /home/tdebrand/PSU_2016_tetris/src/core/menu
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Mar 21 20:33:03 2017 Thomas DEBRAND PASSARD
** Last update Wed Mar 22 03:51:57 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "menu.h"
#include "struct.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <term.h>

char const      (* const choices[]) =
{
  "Start Game",
  "Commands",
  "Help",
  "Themes",
  "Exit",
};

void	selectek(t_game game, t_world *world, int i, WINDOW *win)
{
  (i == 4 ? quit() : 0);
  (i == 0 ? launch_game(game, world) : 0);
  (i == 3 ? print_theme1(world, win) : 0);
  (i == 1 ? print_command(win, world) : 0);
}

void	init_wincolor()
{
  init_color(8, 9, 9, 9);
  init_color(9, 1000, 400, 800);
  init_color(10, 1000, 600, 0);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
  init_pair(8, 9, COLOR_BLACK);
  init_pair(9, 10, COLOR_BLACK);
  init_pair(10, 11, COLOR_BLACK);
}

void	print_menu(t_game game, t_world *world)
{
  char	key[1024];
  int   i = -1;
  WINDOW	*menu_win;

  initscr();
  start_color();
  init_wincolor();
  menu_win = subwin(stdscr, 12, 30, LINES / 2 - 5, COLS / 2 - 15);
  box(menu_win, ACS_VLINE, ACS_HLINE);
  move_selected(menu_win, &i, 1);
  while (1)
    {
      if (my_strlen(read_keys(key)) > 0)
	{
	  if (equals(key, world->key[0]))
	    move_selected(menu_win, &i, 0);
	  else if (equals(key, world->key[1]))
	    move_selected(menu_win, &i, 1);
	  else if (equals(key, world->enter))
	    {
	      selectek(game, world, i--, menu_win);
	      move_selected(menu_win, &i, 1);
	    }
	  key[0] = 0;
	}
    }
}

void	move_selected(WINDOW *win, int *pos, char dir)
{
  int	i;

  i = 0;
  wclear(win);
  box(win, ACS_VLINE, ACS_HLINE);
  *pos += dir ? 1 : -1;
  *pos = *pos > 4 ? 0 : *pos;
  *pos = *pos < 0 ? 4 : *pos;
  while (i++ < 5)
    {
      if (i - 1 != *pos)
	mvwprintw(win, 1 + i, 2, "%s", choices[i - 1]);
      else
	{
	  wattron(win, A_REVERSE);
          mvwprintw(win, 1 + i, 2, "%s", choices[i - 1]);
          wattroff(win, A_REVERSE); 
	}
    }
  wrefresh(win);
}
