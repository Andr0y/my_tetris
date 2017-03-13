/*
** my_realloc.c for my_realloc in /home/Froxy/PSU_2016_tetris
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Tue Feb 28 12:03:11 2017 Yoann Kersulec
** Last update Tue Feb 28 16:03:13 2017 Yoann Kersulec
*/

#include "tetris.h"

char    *my_realloc(char *save, int size)
{
  int   i;
  char  *new;

  i = 0;
  if ((new = malloc(sizeof(*new) * (my_strlen(save) + size))) == NULL)
    return (NULL);
  while (save[i] != '\0')
    {
      new[i] = save[i];
      i = i + 1;
    }
  return (new);
}
