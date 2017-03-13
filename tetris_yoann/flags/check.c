/*
** check.c for check in /home/Froxy/PSU_2016_tetris/core
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Mon Feb 27 17:33:30 2017 Yoann Kersulec
** Last update Mon Mar 13 13:42:14 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

static g_arguments arguments[]= {
  {"-d", "--debug"},
  {"-w", "--without-next"},
  {"", "--map-size="},
  {"-kp", "--key-pause="},
  {"-kq", "--key-quit="},
  {"-kd", "--key-drop="},
  {"-kt", "--key-turn="},
  {"-kr", "--key-right="},
  {"-kl", "--key-left="},
  {"-l", "--level="}
};

int     check_debug_help(char **argv1, int argc)
{
  int   i;
  int   return_value;

  i = 1;
  return_value = 0;
  while (i < argc)
    {
      if (my_strcmp(argv1[i], "-d") == 0)
	return_value = return_value + 1;
      if (my_strcmp(argv1[i], "--help") == 0)
	return_value = return_value + 2;
      i = i + 1;
    }
  return (return_value);
}

int	check_real_flags_2(char *arg, char *save, int size)
{
  int	x;
  int	egal;

  x = 0;
  if ((egal = count_for_r(arg)) != 0)
    {
      save = NULL;
      save = malloc(sizeof(char) * (size - 2));
      save = my_strncpy(arg, save, (size - 2));
      while (x < 10)
	{
	  if (my_strncmp(save, arguments[x].real_flags, egal) == 0)
	    return (egal);
	  x = x + 1;
	}
    }
  return (-1);
}

int	check_real_flags(char *arg)
{
  int	size;
  char	*save;
  int	egal;

  size = my_strlen(arg);
  save = NULL;
  if ((egal = check_real_flags_2(arg, save, size)) == -1)
    return (-1);
  return (0);
}

int     check_flags(char *arg)
{
  int   i;

  i = 0;
  while (i < 10)
    {
      if (my_strcmp(arg, arguments[i].flags) == 0)
	return (1);
      i = i + 1;
    }
  return (-1);
}

int     check_arg(char **args, int i)
{
  int   size1;

  size1 = my_strlen(args[i]);
  if (my_strcmp(args[i], "--help") == 0 || my_strcmp(args[i], "-d" ) == 0
      || my_strcmp(args[i], "-w" ) == 0)
    return (0);
  if (args[i][0] != '-')
    return (check_for_normal(args[i], args[i - 1]));
  if (size1 <= 3)
    {
      if (check_flags(args[i]) == -1)
	return (-1);
      if (args[i + 1] == NULL)
	return (-1);
      if (check_flags_arg(args[i + 1]) == -1)
      	return (-1);
    }
  else
    {
      if (check_real_flags(args[i]) == -1)
	return (-1);
    }
  return (0);
}
