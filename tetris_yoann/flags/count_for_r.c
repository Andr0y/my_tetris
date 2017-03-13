/*
** count_for_r.c for count_for_r in /home/Froxy/PSU_2016_tetris
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Wed Mar  1 11:55:48 2017 Yoann Kersulec
** Last update Wed Mar  1 11:57:15 2017 Yoann Kersulec
*/

int	count_for_r(char *arg)
{
  int	i;

  i = 0;
  while (arg[i] != '\0')
    {
      if (arg[i] == '=')
	{
	  i = i + 1;
	  return (i);
	}
      i = i + 1;
    }
  return (0);
}
