##
## Makefile for makefile in /home/Froxy/Graphical
## 
## Made by Yoann Kersulec
## Login   <Froxy@epitech.net>
## 
## Started on  Mon Jan  2 12:44:20 2017 Yoann Kersulec
## Last update Mon Mar 13 11:51:39 2017 Yoann Kersulec
##

NAME	= tetris

CFLAGS = -Wall -Wextra -Werror -I ./include  -g3

SRCS	= main.c \
	  tools/my_putstr.c \
	  tools/my_getnbr.c \
	  tools/my_put_nbr.c \
	  tools/my_putchar.c \
	  tools/my_strcmp.c \
	  tools/my_strncmp.c \
	  tools/my_strlen.c \
	  tools/my_strncpy.c \
	  tools/my_strcat.c \
	  tools/my_strcpy.c \
	  tools/my_realloc.c \
	  tools/tab_allocation.c \
	  tools/print_car.c \
	  tools/my_str_to_wordtab.c \
	  flags/print_h.c \
	  flags/check.c \
	  flags/check_flag.c \
	  flags/count_for_r.c \
	  open_tetri/open_tetri.c \
	  open_tetri/get_param.c \
	  open_tetri/check_size.c \
	  open_tetri/affichage.c \
	  open_tetri/remp_all.c \
	  open_tetri/cut_all.c \
	  open_tetri/set_all.c
##	  getnextline/getnextline.c 

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean
