/*
** my_putstr.c for my_putstr.c in /home/Froxy/CPool_Day07/lib/my
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Wed Oct 12 07:50:32 2016 Yoann Kersulec
** Last update Wed Feb  1 09:55:58 2017 Yoann Kersulec
*/

#include <unistd.h>

int	my_putstr(char *str, int channel)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(channel, &str[i], 1);
      i = i + 1;
    }
  return (0);
}
