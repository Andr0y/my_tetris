/*
** check_flag.c for  in /home/Froxy/PSU_2016_tetris/core
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Mon Feb 27 19:44:37 2017 Yoann Kersulec
** Last update Mon Mar 13 13:49:49 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

int     check_flags_arg(char *arg2)
{
  int   size;

  size = my_strlen(arg2);
  if (size > 1)
    return (-1);
  if ((arg2[0] < 64 && arg2[0] > 91) ||
      (arg2[0] < 96 && arg2[0] > 123))
    return (-1);
  return (0);
}

int     check_for_normal(char *arg1, char *arg2)
{
  if (arg1[0] != '-' && (my_strcmp(arg2, "-w") == 0))
    return (-1);
  if (arg1[0] != '-' && arg2[0] == '-')
    return (0);
  return (-1);
}
