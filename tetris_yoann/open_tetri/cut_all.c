/*
** cut_all.c for cut_all in /home/Yoann_k/PSU_2016_tetris/open_tetri
** 
** Made by Yoann Kersulec
** Login   <Yoann_k@epitech.net>
** 
** Started on  Fri Mar 10 15:37:53 2017 Yoann Kersulec
** Last update Mon Mar 13 12:06:13 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

int	count_for_star(char *piece, int i)
{
  int	size;
  int	place;

  size = 0;
  place = i;
  while (piece[place] != '\n')
    {
      place = place + 1;
      size = size + 1;
    }
  while (piece[place] != '*')
    {
      place = place - 1;
      size = size - 1;
    }
  return (size);
}

char		*cut_space(char *piece)
{
  t_comptor	comptor;
  char		*new;

  comptor.i = 1;
  comptor.j = 0;
  new = malloc(sizeof(char) * (my_strlen(piece) + 1));
  while (piece[comptor.i] != '\0')
    {
      comptor.c = 0;
      comptor.k = count_for_star(piece, comptor.i);
      while (comptor.c <= comptor.k)
	{
	  new[comptor.j] = piece[comptor.i];
	  comptor.j = comptor.j + 1;
	  comptor.i = comptor.i + 1;
	  comptor.c = comptor.c + 1;
	}
      while (piece[comptor.i] != '\n')
	comptor.i = comptor.i + 1;
      new[comptor.j] = piece[comptor.i];
      comptor.j = comptor.j + 1;
      comptor.i = comptor.i + 1;
    }
  new[comptor.j] = '\0';
  return (new);
}
