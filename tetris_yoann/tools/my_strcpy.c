/*
** my_strcpy.c for my_strcpy in /home/Froxy/PSU_2016_tetris/tools
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Tue Feb 28 11:43:13 2017 Yoann Kersulec
** Last update Tue Feb 28 11:46:11 2017 Yoann Kersulec
*/

char	*my_strcpy(char *src, char *dest)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
