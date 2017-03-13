/*
** my_getnbr.c for my_getnbr.c in /home/Froxy/CPE_2016_matchstick/tools
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Tue Feb 28 19:27:00 2017 Yoann Kersulec
** Last update Tue Feb 28 19:27:01 2017 Yoann Kersulec
*/

int	my_getnbr(char *str)
{
  int	i;
  int	stock;

  i = 0;
  stock = 0;
  if (str[i] == '-')
    i = i + 1;
  while (str[i] != '\0')
    {
      stock = stock + str[i] - '0';
      stock = stock * 10;
      i = i + 1;
    }
  stock = stock / 10;
  if (str[0] == '-')
    return (stock * (-1));
  else
    return (stock);
}
