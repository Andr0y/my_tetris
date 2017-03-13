/*
** my_get_nbr.c for my_getnbr in /home/Yoann_k/PSU_2016_tetris/tools
** 
** Made by Yoann Kersulec
** Login   <Yoann_k@epitech.net>
** 
** Started on  Thu Mar  2 16:56:39 2017 Yoann Kersulec
** Last update Thu Mar  2 17:00:42 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

int	my_getnbr(char *str)
{
  int	i;
  int	sign;
  int	result;

  sign = 1;
  result = 0;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	sign = sign * (-1);
      i = i + 1;
    }
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      result = result * 10;
      result = str[i] - 48;
      i = i + 1;
    }
  if (sign == -1)
    result = result * (sign);
  return (result);
}
