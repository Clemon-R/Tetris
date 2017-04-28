/*
** theme.c for  in /home/tdebrand/PSU_2016_tetris/src/core/menu
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Mar 21 20:46:20 2017 Thomas DEBRAND PASSARD
** Last update Wed Mar 22 03:04:53 2017 Thomas DEBRAND PASSARD
*/

#include "menu.h"
#include "struct.h"
#include "utils.h"
#include <ncurses.h>

void	print_theme1(t_world *world, WINDOW *theme)
{
  wclear(theme);
  box(theme, ACS_VLINE, ACS_HLINE);
  wattron(theme, COLOR_PAIR(1));
  mvwprintw(theme, 1, 1, "Press 1 for : Red");
  wattroff(theme, COLOR_PAIR(1));
  wattron(theme, COLOR_PAIR(2));
  mvwprintw(theme, 2, 1, "Press 2 for : Green");
  wattroff(theme, COLOR_PAIR(2));
  wattron(theme, COLOR_PAIR(3));
  mvwprintw(theme, 3, 1, "Press 3 for : Yellow");
  wattroff(theme, COLOR_PAIR(3));
  wattron(theme, COLOR_PAIR(4));
  mvwprintw(theme, 4, 1, "Press 4 for : Blue");
  wattroff(theme, COLOR_PAIR(4));
  print_theme2(theme, world);
}

void	print_theme2(WINDOW *theme, t_world *world)
{
  wattron(theme, COLOR_PAIR(5));
  mvwprintw(theme, 5, 1, "Press 5 for : Magenta");
  wattroff(theme, COLOR_PAIR(5));
  wattron(theme, COLOR_PAIR(6));
  mvwprintw(theme, 6, 1, "Press 6 for : Cyan");
  wattroff(theme, COLOR_PAIR(6));
  wattron(theme, COLOR_PAIR(7));
  mvwprintw(theme, 7, 1, "Press 7 for : White");
  wattroff(theme, COLOR_PAIR(7));
  wattron(theme, COLOR_PAIR(8));
  mvwprintw(theme, 8, 1, "Press 8 for : Pink");
  wattroff(theme, COLOR_PAIR(8));
  wattron(theme, COLOR_PAIR(9));
  mvwprintw(theme, 9, 1, "Press 9 for : Orange");
  wattroff(theme, COLOR_PAIR(9));
  wrefresh(theme);
  theme_section(world);
}

void	theme_section(t_world *world)
{
  int	c = 0;
  char	key[124];

  while (1)
    {
      if (my_strlen(read_keys(key)) > 0 && themes(world, key))
	return;
    }
}
