/*
** my_putchar.c for my_putchar in /home/Froxy/matchstick
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Tue Feb 14 12:50:45 2017 Yoann Kersulec
** Last update Tue Feb 14 13:11:53 2017 Yoann Kersulec
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
