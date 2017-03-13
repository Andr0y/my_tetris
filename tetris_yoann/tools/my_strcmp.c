/*
** my_strcmp.c for my_strcmp in /home/Froxy/PSU_2016_my_ls
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Wed Nov 30 17:02:16 2016 Yoann Kersulec
** Last update Thu Mar  9 14:36:22 2017 Yoann Kersulec
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i = i + 1;
  return (s1[i] - s2[i]);
}
