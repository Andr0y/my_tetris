/*
** set_box.c for  in /home/tbesson/projet_psu/Tetris
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Fri Mar  3 14:41:45 2017 Tamsi Besson
** Last update Fri Mar  3 18:01:34 2017 Tamsi Besson
*/

#include "tetris.h"

WINDOW *box_game(char **av)
{
  WINDOW* win;

  win = newwin(my_getnbr(av[1]), my_getnbr(av[2]), 2, COLS / 2 - my_getnbr(av[1]) / 2);
  wclear(win);
  wattron(win, COLOR_PAIR(2));
  box(win, 0, 0);
  wattroff(win, COLOR_PAIR(2));
  bkgd(COLOR_PAIR(1));
  return (win);
}

WINDOW *box_level(char **av)
{
  WINDOW *win;

  win = newwin(my_getnbr(av[1]) / 5, my_getnbr(av[2]) / 5, LINES - my_getnbr(av[1]) / 5, 0);
  wclear(win);
  wattron(win, COLOR_PAIR(2));
  box(win, 0, 0);
  wattroff(win, COLOR_PAIR(2));
  return (win);
}

WINDOW *box_current(char **av)
{
  WINDOW *win;

  win = newwin(my_getnbr(av[1]) / 5, my_getnbr(av[2]) / 5, 0, 0);
  wclear(win);
  wattron(win, COLOR_PAIR(2));
  box(win, 0, 0);
  wattroff(win, COLOR_PAIR(2));
  return (win);
}

WINDOW *box_next(char **av)
{
  WINDOW *win;

  win = newwin(my_getnbr(av[1]) / 5, my_getnbr(av[2]) / 5, 0, COLS - my_getnbr(av[2]) / 5);
  wclear(win);
  wattron(win, COLOR_PAIR(2));
  box(win, 0, 0);
  wattroff(win, COLOR_PAIR(2));
  return (win);
}

void refresh_loop(s_window win)
{
  clear();
  while (1)
    {
      refresh();
      mvprintw(COLS / 2, 1, "TETRIS");
      mvwprintw(win.level, 1, 1, "LEVEL");
      mvwprintw(win.level, 3, 4, "1");
      mvwprintw(win.current, 1, 1, "HOLD");
      mvwprintw(win.next, 1, 1, "NEXT");
      wrefresh(win.level);
      wrefresh(win.game);
      wrefresh(win.current);
      wrefresh(win.next);
    }
  endwin();
}
