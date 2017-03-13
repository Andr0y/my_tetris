/*
** get_param.c for get_param in /home/Yoann_k/PSU_2016_tetris/open_tetri
** 
** Made by Yoann Kersulec
** Login   <Yoann_k@epitech.net>
** 
** Started on  Thu Mar  2 16:41:42 2017 Yoann Kersulec
** Last update Fri Mar 10 16:45:52 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

int	remp_width(t_tetrimino *tetri, char *save, int i)
{
  tetri->width[i] = save[i];
  i = i + 1;
  return (i);
}

int	remp_weigth(t_tetrimino *tetri, char *save, int i)
{
  int	j;

  j = 0;
  while (save[i] > 47 && save[i] < 58)
    {
      tetri->weigth[j] = save[i];
      i = i + 1;
      j = j + 1;
    }
  return (i);
}

int	remp_color(t_tetrimino *tetri, char *save, int i)
{
  int	j;

  j = 0;
  while (save[i] > 47 && save[i] < 58)
    {
      tetri->color[j] = save[i];
      i = i + 1;
      j = j+ 1;
    }
  return (i);
}
int	stack_nb(char *save, t_tetrimino *tetri)
{
  int	i;

  i = 0;
  if (save[i] < 48 || save[i] > 57)
    return (-1);
  while (save[i] > 48 && save[i] < 58)
    i = remp_width(tetri, save, i);
  if (save[i] != ' ' || save[i + 1] < 48 || save[i + 1] > 57)
    return (-1);
  i = i + 1;
  if (save[i] > 48 && save[i] < 58)
    i = remp_weigth(tetri, save, i);
  else
    return (-1);
  if (save[i] != ' ' || save[i + 1] < 48 || save[i + 1] > 57)
    return (-1);
  i = i + 1;
  if (save[i] > 47 && save[i] < 58)
    i = remp_color(tetri, save, i);
  else
    return (-1);
  if (save[i] != '\0')
    return (-1);
  return (0);
}

char		*get_param(char *save, char *piece)
{
  int		size;
  t_tetrimino	tetri;

  size = (my_strlen(save) + my_strlen(piece));
  if ((tetri.width = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  if ((tetri.weigth = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  if ((tetri.color = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  if (stack_nb(save, &tetri) == -1)
    {
      save = my_strcpy("Error", save);
      return (save);
    }
  if (check_size(&tetri, piece) == -1)
    {
      save = my_strcpy("Error", save);
      return (save);
    }
  save = my_strcat(save, "\n");
  save = my_strcat(save, cut_space(piece));
  return (save);
}
