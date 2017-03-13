/*
** my_strncpy.c for my_strncpy in /home/Froxy/PSU_2016_tetris
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Mon Feb 27 18:29:04 2017 Yoann Kersulec
** Last update Mon Feb 27 18:31:06 2017 Yoann Kersulec
*/

char	*my_strncpy(char *str1, char *str2, int size)
{
  int	i;

  i = 0;
  while (size > 0 && str1[i] != '\0')
    {
      str2[i] = str1[i];
      i = i + 1;
      size = size - 1;
    }
  if (size > 0)
    str2[i + 1] = '\0';
  return (str2);
}
