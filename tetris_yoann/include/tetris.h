/*
** tetris.h for tetris in /home/Froxy/PSU_2016_tetris/include
** 
** Made by Yoann Kersulec
** Login   <Froxy@epitech.net>
** 
** Started on  Mon Feb 27 16:31:03 2017 Yoann Kersulec
** Last update Mon Mar 13 12:02:16 2017 Yoann Kersulec
*/

#ifndef TETRIS_H
# define TETRIS_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct g_keybind
{
  char *nickname;
  char *name;
  char *disp;
  char *value;
}	g_keybind;

typedef struct g_arguments
{
  char	*flags;
  char	*real_flags;
}	g_arguments;

typedef struct s_tetrimino
{
  char	*name;
  char 	*width;
  char	*weigth;
  char	*color;
  char	*error;
}	t_tetrimino;

typedef struct s_comptor
{
  int	i;
  int	j;
  int	k;
  int	c;
}	t_comptor;

char	**my_str_to_wordtab(char *, char);
int	my_putstr(char *, int);
void	my_putchar(char);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
int	my_strlen(char *);
void	my_put_nbr(int);
char	*my_strncpy(char *, char *, int);
char	*my_strcat(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_realloc(char *, int);
int	my_getnbr(char *);
int	print_car(char *, char, int);
char	**tab_allocation(char **, int, int);
int	print_h(char *);
int	check_for_d(char **);
int	check_debug_help(char **, int);
int	check_arg(char **, int);
int	check_flags_arg(char *);
int	check_for_normal(char *, char *);
char	**open_tetri(char *);
int	count_for_r(char *);
char	*get_param(char *, char *);
char    *remp_first_line(char *, t_comptor *comptor, char *);
char    *remp_rest_line(char *, t_comptor *comptor, char *);
int	check_size(t_tetrimino *tetris, char *);
char    *cut_space(char *);
int	affich(char **, char *);
char	**set_all(char **, int, t_comptor *cpt);
char    *set_for_name(struct dirent *open_file, char **, char *, int);
#endif // TETRIS //
