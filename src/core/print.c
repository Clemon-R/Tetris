/*
** print.c for  in /home/tdebrand/PSU_2016_tetris
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Mar 21 23:14:57 2017 Thomas DEBRAND PASSARD
** Last update Wed Mar 22 02:43:55 2017 Thomas DEBRAND PASSARD
*/

#include "utils.h"
#include "struct.h"
#include "print.h"
#include "menu.h"
#include <ncurses.h>
#include <stdlib.h>

void	init_graphic(WINDOW **score, WINDOW **game, WINDOW **next
		     , WINDOW **timer)
{
  *timer = subwin(stdscr, 3, 20, 13, 3);
  *score = subwin(stdscr, 9, 20, 4, 3);
  box(*timer, ACS_VLINE, ACS_HLINE);
  box(*next, ACS_VLINE, ACS_HLINE);
  box(*game, ACS_VLINE, ACS_HLINE);
  box(*score, ACS_VLINE, ACS_HLINE);
}

void	load_next(WINDOW *form, t_game *party, t_world *world)
{
  int	i = 0;

  wattron(form, COLOR_PAIR(world->theme));
  mvwprintw(form, 1, 1, "Next :");
  wattroff(form, COLOR_PAIR(world->theme));
  while (party->next->data[i] && ++i)
    {
      wattron(form, COLOR_PAIR(party->next->color));
      mvwprintw(form, i + 1, 1, party->next->data[i - 1]);
      wattroff(form, COLOR_PAIR(party->next->color));
    }
}

void	load_score(WINDOW *form, t_game *party, t_world *world)
{
  wattron(form, COLOR_PAIR(world->theme));
  mvwprintw(form, 1, 7, "TETRIS");
  mvwprintw(form, 3, 1, "High score : ");
  my_print_nbr(form, 15, 3, party->score[1]);
  mvwprintw(form, 4, 1, "Score : ");
  my_print_nbr(form, 10, 4, party->score[0]);
  mvwprintw(form, 6, 1, "Lines : ");
  my_print_nbr(form, 10, 6, party->lines);
  mvwprintw(form, 7, 1, "Level : ");
  my_print_nbr(form, 10, 7, party->level);
  wattroff(form, COLOR_PAIR(world->theme));
}

void	load_timer(t_game party, t_world *world, WINDOW *form)
{
  long	timer;

  timer = get_timer() - party.time;
  wattron(form, COLOR_PAIR(world->theme));
  mvwprintw(form, 1, 1, "Timer : ");
  my_print_nbr(form, 10, 1, timer / 60);
  mvwprintw(form, 1, 11, ":");
  my_print_nbr(form, 12, 1, timer % 60);
  wattroff(form, COLOR_PAIR(world->theme));
}

WINDOW	*print_game(t_game party, t_world world)
{
  WINDOW        *score;
  WINDOW        *game;
  WINDOW        *next;
  WINDOW        *timer;

  clear();
  start_color();
  next = subwin(stdscr, party.next->height + 3
		, (party.next->width < 6 ? 6 : party.next->width) + 2, 4
		, 27 + world.size[0]);
  game = subwin(stdscr, world.size[1] + 2, world.size[0] + 2, 4, 25);
  init_graphic(&score, &game, &next, &timer);
  load_next(next, &party, &world);
  load_score(score, &party, &world);
  load_timer(party, &world, timer);
  refresh();
  return (game);
}
