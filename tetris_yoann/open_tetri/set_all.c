/*
** set_all.c for set_all in /home/Yoann_k/PSU_2016_tetris/open_tetri
** 
** Made by Yoann Kersulec
** Login   <Yoann_k@epitech.net>
** 
** Started on  Mon Mar 13 11:46:05 2017 Yoann Kersulec
** Last update Mon Mar 13 12:04:07 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

char	**set_all(char **get_s, int i, t_comptor *cpt)
{
  cpt->i = 0;
  get_s = NULL;
  get_s = tab_allocation(get_s, i, 100);
  return (get_s);
}

char	*set_for_name(struct dirent *open_file, char **file_path,
		      char *path, int i)
{
  char	*file_name;

  file_name = malloc(sizeof(char) * 40);
  file_name = my_strcpy(file_name, open_file->d_name);
  file_path[i] = my_strcpy(path, file_path[i]);
  file_path[i] = my_strcat(file_path[i], file_name);
  return (file_path[i]);
}
