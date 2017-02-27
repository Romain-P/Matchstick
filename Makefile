##
## makefile for make in /home/jordan.roucom/CPool_rush3
## 
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
## 
## Started on  Sat Oct 29 17:09:21 2016 romain pillot
## Last update Sun Feb 26 21:50:13 2017 romain pillot
##

CC	=	gcc

NAME	=	matchstick

RM	=	rm -f

SRCS	=	src/main.c		\
		src/map.c		\
		src/turn.c		\
		src/util/scanner.c	\
		src/util/number.c	\
		src/util/display.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Werror -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
