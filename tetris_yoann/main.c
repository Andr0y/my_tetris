/*
** main.c for main in /home/Froxy/PSU_2016_tetris
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Tue Feb 21 17:41:07 2017 Yoann Kersulec
** Last update Mon Mar 13 13:57:01 2017 Yoann Kersulec
*/

#include "include/tetris.h"

static g_keybind keybinds[] =
  {
    {"-kl", "--key-left", "Key Left : ", "Q"},
    {"-kr", "--key-right", "Key Right : ", "D"},
    {"-kt", "--key-turn", "Key Turn : ", "(space)"},
    {"-kd", "--key-drop", "Key Drop : ", "x"},
    {"-kq", "--key-quit", "Key Quit : ", "a"},
    {"-kp", "--key-pause", "Key Pause : ", "p"},
    {"-w", "--without-next", "Next : ", "Yes"},
    {"-l", "--level", "Level : ", "1"},
    {"-mapsize", "--map-size", "Size : ", "20*10"}
  };

void	disp_keybindings()
{
  int	i;

  i = 0;
  my_putstr("*** DEBUG MODE ***\n", 1);
  while (i <= 8)
    {
      my_putstr(keybinds[i].disp, 1);
      if (my_strcmp(keybinds[i].value, " ") == 0)
	keybinds[i].value = "(space)";
      my_putstr(keybinds[i].value, 1);
      my_putstr("\n", 1);
      i++;
    }
}

void	set_values(int argc, char **argv)
{
  int	i;
  int	j;
  char	**tab_2d;

  i = 1;
  while (i < argc)
    {
      j = 0;
      while (j <= 8)
	{
	  if ((my_strcmp(argv[i], "-w"))== 0)
	    keybinds[6].value = "No";
	  else if (my_strcmp(argv[i], keybinds[j].nickname) == 0)
	    keybinds[j].value = argv[i + 1];
	  tab_2d = my_str_to_wordtab(argv[i], '=');
	  if (my_strcmp(tab_2d[0], keybinds[j].name) == 0)
	    keybinds[j].value = tab_2d[1];
	  j++;
	}
      i++;
    }
}

int	check_in_main_arg(char **argv, int i, int check)
{
  if (check_arg(argv, i) == -1)
    {
      if (check != 84)
	return (print_h(argv[0]));
      return (84);
    }
  return (0);
}

int	launcher(char **argv)
{
  char	**recup;

  if ((recup = open_tetri("tetrimino/")) == NULL)
    return (84);
  if (check_for_d(argv) == 1)
    {
      disp_keybindings();
      affich(recup, "tetrimino/");
    }
  return (0);
}

int	main(int argc, char **argv)
{
  int	i;
  int	check;

  i = 1;
  if (argc == 1)
    return (print_h(argv[0]));
  if ((check_debug_help(argv, argc)) == 2
      || (check_debug_help(argv, argc)) == 3)
    check = print_h(argv[0]);
  while (i < argc)
    {
      if ((check_in_main_arg(argv, i, check)) == 84)
	return (84);
      i = i + 1;
    }
  i = 0;
  while (i < argc)
    {
      if (my_strcmp(argv[i], "-d") == 0)
	set_values(argc, argv);
      i++;
    }
  if ((launcher(argv)) == 84)
    return (84);
  my_putstr("Press any key to start Tetris\n" , 1);
  return (0);
}
