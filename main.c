/*
** main.c for  in /home/tbesson/projet_psu/Tetris
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Wed Mar  1 13:53:59 2017 Tamsi Besson
** Last update Fri Mar  3 18:01:41 2017 Tamsi Besson
*/

#include "tetris.h"

int main (int ac, char **av)
{
  s_window win;
  char **map;

  if (ac == 1)
    {
      av[1] = "65";
      av[2] = "80";
    }
  initscr();
  start_color();
  curs_set(0);
  init_pair(1, COLOR_BLACK, COLOR_CYAN);
  init_pair(2, COLOR_BLUE, COLOR_BLUE);
  win.game = box_game(av);
  win.level = box_level(av);
  win.current = box_current(av);
  win.next = box_next(av);
  map = game_map(map, av);
  refresh_loop(win, map);
  return (0);
}
