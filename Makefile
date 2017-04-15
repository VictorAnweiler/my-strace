##
## Makefile for strace in /home/rootkid/rendu/psu/PSU_2016_strace
## 
## Made by theo champion
## Login   <theo.champion@epitech.eu>
## 
## Started on  Wed Apr 12 11:17:49 2017 theo champion
## Last update Sat Apr 15 20:25:02 2017 theo champion
##

CC	= cc

RM	= rm -f

SRCDIR	= .

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I.

NAME	= strace

SRCS	= $(SRCDIR)/main.c		\
          $(SRCDIR)/trace.c		\
	  $(SRCDIR)/getpath.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
