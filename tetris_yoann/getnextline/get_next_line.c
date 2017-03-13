/*
** get_next_line.c for get_next_line in /home/Froxy/CPE_2016_getnextline
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Sun Jan 15 19:33:51 2017 Yoann Kersulec
** Last update Tue Feb 28 12:02:51 2017 Yoann Kersulec
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char	*my_realloc(char *save, int size)
{
  int	i;
  char	*new;

  i = 0;
  if ((new = malloc(sizeof(*new) * (my_strlen(save) + size))) == NULL)
    return (NULL);
  while (save[i] != '\0')
    {
      new[i] = save[i];
      i = i + 1;
    }
  free(save);
  return (new);
}

char	*end_line(t_getline *line, char *deb)
{
  line->i = 0;
  line->size = line->size - 1;
  return (deb);
}

char	*check(t_getline *line, char *deb, char *buffer)
{
  deb[line->i] = buffer[my_strlen(buffer) - line->size];
  line->i = line->i + 1;
  line->size = line->size - 1;
  return (deb);
}

char			*get_next_line(const int fd)
{
  static t_getline	line;
  static char		*deb = NULL;
  static char		buffer[READ_SIZE];

  if (buffer[my_strlen(buffer) - line.size] == '\0')
    {
      if ((line.size = read(fd, buffer, READ_SIZE)) <= 0)
	return (deb = (line.last = line.last - 1 &&
		       buffer[my_strlen(buffer) - line.size - 1] != 10) ? deb : NULL);
      buffer[line.size] = '\0';
    }
  if ((deb = (line.i == 0) ? malloc(sizeof(*deb) * READ_SIZE + 1) :
       my_realloc(deb, sizeof(*deb) * READ_SIZE + 1)) == NULL)
    return (NULL);
  while (buffer[my_strlen(buffer) - line.size] != '\0'
	 && buffer[my_strlen(buffer) - line.size] != '\n')
    check(&line, deb, buffer);
  deb[line.i] = '\0';
  if (buffer[my_strlen(buffer) - line.size] == '\n')
    {
      deb = end_line(&line, deb);
      return (deb);
    }
  return (get_next_line(fd));
}
