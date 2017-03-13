/*
** my_strcat.c for my_strcat in /home/Froxy/PSU_2016_my_ls
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Thu Dec  1 12:03:32 2016 Yoann Kersulec
** Last update Tue Feb 28 16:02:14 2017 Yoann Kersulec
*/

#include "tetris.h"

char	*my_strcat(char *src, char *dest)
{
  int	len;
  int	i;

  len = my_strlen(src);
  i = 0;
  while (dest[i] != '\0')
    {
      src[len + i] = dest[i];
      i = i + 1;
    }
  src[len + i] = '\0';
  return (src);
}
