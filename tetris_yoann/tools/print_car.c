/*
** print_car.c for print_car in /home/Yoann_k/PSU_2016_tetris/tools
** 
** Made by Yoann Kersulec
** Login   <Yoann_k@epitech.net>
** 
** Started on  Mon Mar  6 16:58:33 2017 Yoann Kersulec
** Last update Mon Mar  6 17:01:35 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

int	print_car(char *str, char delim, int i)
{
  while (str[i] != delim)
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (i);
}
