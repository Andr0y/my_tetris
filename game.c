/*
** game.c for  in /home/tbesson/projet_psu/Tetris
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Fri Mar  3 14:20:16 2017 Tamsi Besson
** Last update Fri Mar  3 18:03:26 2017 Tamsi Besson
*/

#include "tetris.h"

char **malloc_map2d(int size, int len, char **map)
{
  int i;

  i = 0;
  map = malloc (len * sizeof(char *));
  while (i < size + 1)
    {
      map[i] = malloc (size * sizeof(char) + 1);
      i++;
    }
  return (map);
}

char **game_map(char **tetris, char **av)
{
  int x;
  int y;
  int i;
  int j;

  x = my_getnbr(av[2]) - 1;
  y = my_getnbr(av[1]) - 1;
  tetris = malloc_map2d(y, x, tetris);
  i = 0;
  while (i < y)
    {
      j = 0;
      while  (j < x)
        {
          tetris[i][j] = ' ';
          j++;
        }
      i++;
    }
  return (tetris);
}

void set_tetrimino(char **map, int k, int i, char *tetrimino)
{
  int j;

  j = 0;
  while (tetrimino[j])
  {
    if (tetrimino[j] == '\n')
      k++;
    else
      map[k][i] = tetrimino[j];
    if (tetrimino[j] == '*' && tetrimino[j + 1] != '\n')
      i++;
    j++;
  }
}

void erase_tetrimino(char **map, int k, int i, char *tetrimino)
{
  int j;

  j = 0;
  while (tetrimino[j])
  {
    if (tetrimino[j] == '\n')
      k++;
    else
      map[k][i] = ' ';
    if (tetrimino[j] == '*' && tetrimino[j + 1] != '\n')
      i++;
    j++;
  }
}

char **disp_map(char **map, WINDOW *game)
{
  int i;
  int j;

  i = 1;
  while (map[i])
    {
      j = 1;
      while  (map[i][j] != '\0')
        {
          mvwaddch(game, i, j, map[i][j]);
          j++;
        }
      i++;
    }
  return (map);
}

void static_tetrimino(char **map)
{
  int i;
  int j;

  i = 1;
  while (map[i])
  {
    j = 1;
    while  (map[i][j] != '\0')
      {
        if (map[i][j] == '*')
          map[i][j] = 's';
        j++;
      }
    i++;
  }
}

int check_collision(char **map)
{
  int j;
  int i;

  j = 1;
  while (map[j])
  {
    i = 1;
    while (map[j][i] != '\0')
    {
      if (map[j][i] == '*' &&
       (map[j + 1][i] != ' ' && map[j + 1][i] != '*'))
        return (1);
      i++;
    }
    j++;
  }
  return (0);
}

int play_tetrimino(char **map, s_window win, int k)
{
  char *tetrimino;
  static int pos = 30;

  tetrimino = "2 3 1*\n*\n**";
  timeout(100);
  char a = getch();
  if (a == 'q' && map[k + 1][pos - 2] == ' ')
    pos--;
  else if (a == 'd' && map[k + 1][pos + (tetrimino[0] - 48)] == ' ')
    pos++;
  if ((check_collision(map)) == 0)
    set_tetrimino(map, k, pos, tetrimino);
  else
  {
    pos = 30;
    static_tetrimino(map);
    return (1);
  }
  usleep(5000);
  map = disp_map(map, win.game);
  if (check_collision(map) == 0)
    erase_tetrimino(map, k, pos, tetrimino);
  k++;
  if (map[k + (tetrimino[2] - 48)] == NULL)
  {
    k = 1;
    pos = 30;
    static_tetrimino(map);
  }
  return (k);
}
