/*
** my_strncmp.c for my_strncmp.c in /home/Froxy/PSU_2016_tetris
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Mon Feb 27 18:15:36 2017 Yoann Kersulec
** Last update Mon Feb 27 18:21:12 2017 Yoann Kersulec
*/

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;

  i = 0;
  while (n > 0 && str1[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (-1);
      i = i + 1;
      n = n - 1;
    }
  return (0);
}
