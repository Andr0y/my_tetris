/*
** get_next_line.h for get_next_line_size in /home/Froxy/CPE_2016_getnextline
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Wed Jan  4 16:24:09 2017 Yoann Kersulec
** Last update Wed Feb 15 23:33:47 2017 Yoann Kersulec
*/

#ifndef READ_SIZE
# define READ_SIZE 2
#endif //SIZE READ//

struct s_getline
{
  int	last;
  int	size;
  int	i;
};
typedef struct s_getline t_getline;
