/*
** remp_all.c for remp_all in /home/Yoann_k/PSU_2016_tetris/open_tetri
** 
** Made by Yoann Kersulec
** Login   <Yoann_k@epitech.net>
** 
** Started on  Fri Mar 10 15:19:26 2017 Yoann Kersulec
** Last update Fri Mar 10 15:24:09 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

char    *remp_first_line(char *buffer, t_comptor *comptor, char *save)
{
  while (buffer[comptor->i] != '\n')
    {
      save[comptor->i] = buffer[comptor->i];
      comptor->i = comptor->i + 1;
    }
  return (save);
}

char	*remp_rest_line(char *buffer, t_comptor *comptor, char *piece)
{
  while (buffer[comptor->i] != '\0')
    {
      piece[comptor->k] = buffer[comptor->i];
      comptor->i = comptor->i + 1;
      comptor->k = comptor->k + 1;
    }
  return (piece);
}
