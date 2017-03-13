/*
** afichage.c for affichage in /home/Yoann_k/PSU_2016_tetris/open_tetri
** 
** Made by Yoann Kersulec
** Login   <Yoann_k@epitech.net>
** 
** Started on  Mon Mar  6 12:29:17 2017 Yoann Kersulec
** Last update Mon Mar 13 12:05:53 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

void	affich_size(char *tetrimino)
{
  int	i;

  i = 0;
  my_putstr("Size : ", 1);
  i = print_car(tetrimino, ' ', i);
  i = i + 1;
  my_putchar('*');
  i = print_car(tetrimino, ' ', i);
  i = i + 1;
  my_putstr(" :  Color ", 1);
  i = print_car(tetrimino, '\n', i);
  i = i + 1;
  my_putstr(" :\n", 1);
  print_car(tetrimino, '\0', i);
}

int	affich_clear(char *tetrimino, struct dirent *dir)
{
  int	i;

  i = 0;
  my_putstr("Name ", 1);
  while (dir->d_name[i] != '.')
    {
      my_putchar(dir->d_name[i]);
      i = i + 1;
    }
  my_putstr(" :  ", 1);
  if (my_strncmp(tetrimino, "Error", 5) == 0)
    {
      my_putstr("Error\n", 1);
      return (0);
    }
  i = 0;
  affich_size(tetrimino);
  return (0);
}

int	clear_arg(char *tetrimino, struct dirent *dir)
{
  if (my_strcmp(dir->d_name, ".") == 0 || my_strcmp(dir->d_name, "..") == 0)
    return (0);
  my_putstr("Tetriminos :  ", 1);
  affich_clear(tetrimino, dir);
  return (0);
}

int		affich(char **tetrimino, char *path_to_te)
{
  int		i;
  int		j;
  int		nb;
  DIR		*rep;
  struct dirent	*dir;

  i = 0;
  while (tetrimino[i])
    {
      if (tetrimino[i] != NULL)
	nb = nb + 1;
      i = i + 1;
    }
  my_putstr("Tetriminos :  ", 1);
  my_put_nbr(nb);
  my_putchar('\n');
  if ((rep = opendir(path_to_te)) == NULL)
    return (-1);
  j = 0;
  while ((dir = readdir(rep)) != NULL)
    {
      clear_arg(tetrimino[j], dir);
      j = j + 1;
    }
  return (0);
}
