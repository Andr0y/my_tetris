/*
** tab_allocation.c for tab_allocation in /home/Froxy/PSU_2016_tetris
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Tue Feb 28 13:51:04 2017 Yoann Kersulec
** Last update Fri Mar  3 15:34:34 2017 Yoann Kersulec
*/

#include "tetris.h"

char	**tab_allocation(char **map, int x, int y)
{
  int	i;

  i = 0;
  if ((map = malloc(sizeof(char *) * (x + 1))) == NULL)
    return (NULL);
  while (i < x)
    {
      if ((map[i] = malloc(sizeof(char) * (y + 1))) == NULL)
	return (NULL);
      i = i + 1;
    }
  return (map);
}
