##
## Makefile for makefile in /home/Froxy/Graphical
## 
## Made by Yoann Kersulec
## Login   <Froxy@epitech.net>
## 
## Started on  Mon Jan  2 12:44:20 2017 Yoann Kersulec
## Last update Fri Mar  3 16:53:31 2017 Tamsi Besson
##

NAME	= tetris

CFLAGS += -Wextra -Wall

SRCS	= main.c \
	  my_getnbr.c \
	  my_strfct.c \
	  set_box.c \
	  game.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME) $(CFLAGS) -lncurses

clean:
	rm -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean
