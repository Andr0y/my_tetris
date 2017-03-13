/*
** my_strlen.c for  in /home/Froxy/PSU_2016_tetris/tools
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Mon Feb 27 13:37:21 2017 Yoann Kersulec
** Last update Mon Feb 27 17:12:23 2017 Yoann Kersulec
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
