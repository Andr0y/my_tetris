/*
** print_h.c for print_h in /home/Froxy/PSU_2016_tetris/core
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Mon Feb 27 17:23:08 2017 Yoann Kersulec
** Last update Fri Mar 10 14:23:15 2017 Yoann Kersulec
*/

#include "../include/tetris.h"

int    print_h(char *exec)
{
  my_putstr("Usage:\t", 1);
  my_putstr(exec, 1);
  my_putstr(" [options]\nOptions:\n", 1);
  my_putstr("   --help\t\tDisplay this help\n", 1);
  my_putstr("   -l --level={num}\tStart Tetris at level num (def:  1)\n", 1);
  my_putstr("   -kl --key-left={K}\tMove the tetrimino LEFT using", 1);
  my_putstr(" the K key (def:  left arrow)\n", 1);
  my_putstr("   -kr --key-right={K}\tMove the tetrimino RIGHT using", 1);
  my_putstr(" the K key (def:  right arrow)\n", 1);
  my_putstr("   -kt --key-turn={K}\tTURN the tetrimino clockwise 90d", 1);
  my_putstr(" using the K key (def:  top arrow)\n", 1);
  my_putstr("   -kd --key-drop={K}\tDROP the tetrimino using K key", 1);
  my_putstr(" (def:  down arrow)\n", 1);
  my_putstr("   -kq --key-quit={K}\tQUIT the game using the K key", 1);
  my_putstr(" (def:  'Q' key)\n", 1);
  my_putstr("   -kp --key-pause={K}\tPAUSE/RESTART the game using K", 1);
  my_putstr(" key (def:  space bar)\n", 1);
  my_putstr("   --map-size={row,col}\tSet the numbers of rows and columns", 1);
  my_putstr(" of the map (def:  20,10)\n", 1);
  my_putstr("   -w --without-next\tHide next tetrimino (def: false)\n", 1);
  my_putstr("   -d --debug\t\tDebug mode (def:  false)\n", 1);
  return (84);
}

int	check_for_d(char **argv)
{
  int	i;

  i = 0;
  while (argv[i])
    {
      if (my_strcmp(argv[i], "-d") == 0)
	return (1);
      i = i + 1;
    }
  return (0);
}
