/*
** tetris.h for  in /home/tbesson/projet_psu/Tetris
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Wed Mar  1 13:51:44 2017 Tamsi Besson
** Last update Fri Mar  3 13:49:07 2017 Tamsi Besson
*/

#ifndef TETRIS_H_
# define TETRIS_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

typedef struct t_window
{
	WINDOW *game;
	WINDOW *level;
	WINDOW *current;
	WINDOW *next;
}	s_window;

long    my_getnbr(char *);
int     my_strlen(char *);
int play_tetrimino(char **, s_window, int);
void set_tetrimino(char **, int, int, char *);
void erase_tetrimino(char **, int, int, char *);
void refresh_loop(s_window, char **);
void disp_tetrimino(char **, WINDOW *, char *);
char    *my_strcat(char *, char *);
char **malloc_map2d(int, int, char **);
char **game_map(char **, char **);
char **disp_map(char **, WINDOW *);
WINDOW *box_game(char **);
WINDOW *box_level(char **);
WINDOW *box_current(char **);
WINDOW *box_next(char **);
#endif //TETRIS_H_
