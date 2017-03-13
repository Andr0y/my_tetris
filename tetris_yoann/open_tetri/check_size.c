/*
** check_size.c for check_size in /home/Yoann_k/PSU_2016_tetris/flags
** 
** Made by Yoann Kersulec
** Login   <Yoann_k@epitech.net>
** 
** Started on  Fri Mar  3 15:47:44 2017 Yoann Kersulec
** Last update Mon Mar 13 10:35:39 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

int	check_space(char *save, int column)
{
  int	size;
  int	space;

  if (column == 0)
    return (column);
  space = 0;
  size = column;
  while (save[size] != '*')
    {
      space = space + 1;
      size = size - 1;
    }
  column = column - (space - 1);
  return (column);
}

int	count_for_all(t_tetrimino *tetri, char *piece, t_comptor *comptor)
{
  char	*save;
  int	column;

  save = NULL;
  save = malloc(sizeof(char) * my_getnbr(tetri->width));
  column = 0;
  while (piece[comptor->i] != '\n')
    {
      if (piece[comptor->i] != ' ' && piece[comptor->i] != '*')
	return (-1);
      save[column] = piece[comptor->i];
      column = column + 1;
      comptor->i = comptor->i + 1;
    }
  column = check_space(save, column);
  if (comptor->k < column)
    comptor->k = column;
  if (column > my_getnbr(tetri->width) || column == 0)
    return (-1);
  comptor->i = comptor->i + 1;
  return (0);
}

int		check_size(t_tetrimino *tetri, char *piece)
{
  int		line;
  t_comptor	comptor;

  line = 0;
  comptor.i = 1;
  comptor.k = 0;
  while (piece[comptor.i] != '\0')
    {
      line = line + 1;
      if ((count_for_all(tetri, piece, &comptor)) == -1)
	return (-1);
    }
  if (comptor.k != my_getnbr(tetri->width))
    return (-1);
  if (line != my_getnbr(tetri->weigth))
    return (-1);
  return (0);
}
