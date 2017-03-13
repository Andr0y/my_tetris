/*
** open_tetri.c for open_tetri in /home/Froxy/PSU_2016_tetris
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Tue Feb 28 10:35:26 2017 Yoann Kersulec
** Last update Mon Mar 13 12:06:47 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

char		*check_car(char *file_path, int size, char *get_car)
{
  int		fd;
  t_comptor	comptor;
  char		*save;
  char		*buffer;
  char		*piece;

  save = malloc(sizeof(char) * 20);
  if ((fd = open(file_path, O_RDONLY)) == -1)
    return (NULL);
  buffer = malloc(sizeof(char) * size);
  read(fd, buffer, size);
  comptor.i = 0;
  save = remp_first_line(buffer, &comptor, save);
  piece = malloc(sizeof(char) * (size - comptor.i));
  comptor.k = 0;
  piece = remp_rest_line(buffer, &comptor, piece);
  if ((get_car = my_strcpy(get_car, get_param(save, piece))) == NULL)
    return (NULL);
  return (get_car);
}

int	check_name(char *file_path, char delim)
{
  int	i;

  i = 0;
  while (file_path[i])
    {
      if (file_path[i] == delim)
	return (0);
      i = i + 1;
    }
  return (-1);
}

int	the_check(t_comptor *cpt, struct stat mystat, char **file_p)
{
  if ((cpt->i = mystat.st_size) > 400 ||
      (cpt->i = mystat.st_size) < 8 ||
      (check_name(file_p[cpt->j], '.') == -1))
    return (-1);
  return (0);
}

char		**get_car(char **file_p, int i, char **get_s)
{
  struct stat	mystat;
  t_comptor	cpt;

  get_s = set_all(get_s, i, &cpt);
  while (cpt.j < i)
    {
      cpt.k = my_strlen(file_p[cpt.j]);
      stat(file_p[cpt.j], &mystat);
      if ((the_check(&cpt, mystat, file_p)) == - 1)
	{
	  get_s[cpt.j] = my_strcpy("Error", get_s[cpt.j]);
	  cpt.j = cpt.j + 1;
	  continue;
	}
      if (file_p[cpt.j][cpt.k - 1] == '.')
	cpt.j = cpt.j + 1;
      else
	{
	  if ((get_s[cpt.j] = check_car(file_p[cpt.j],
					cpt.i, get_s[cpt.j])) == NULL)
	    return (NULL);
	  cpt.j = cpt.j + 1;
	}
    }
  return (get_s);
}

char		**open_tetri(char *path)
{
  DIR		*rep;
  struct dirent	*open_file;
  char		**file_path;
  char		**get_stat;
  int		i;

  rep = NULL;
  rep = opendir(path);
  file_path = NULL;
  file_path = tab_allocation(file_path, 49, 49);
  i = 0;
  if (rep == NULL)
    return (NULL);
  while ((open_file = readdir(rep)) != NULL)
    {
      set_for_name(open_file, file_path, path, i);
      i = i + 1;
    }
  get_stat = NULL;
  if ((get_stat = get_car(file_path, i, get_stat)) == NULL)
    return (NULL);
  return (get_stat);
}
