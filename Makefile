##
## Makefile for strace in /home/rootkid/rendu/psu/PSU_2016_strace
## 
## Made by theo champion
## Login   <theo.champion@epitech.eu>
## 
## Started on  Wed Apr 12 11:17:49 2017 theo champion
## Last update Thu Apr 13 18:27:07 2017 theo champion
##

CC	= cc

RM	= rm -f

SRCDIR	= .

CFLAGS	+= -Wall -Wextra -Werror -lm -g3
CFLAGS	+= -I.

NAME	= strace

SRCS	= $(SRCDIR)/main.c		\
          $(SRCDIR)/trace.c		\
          $(SRCDIR)/syscalls_entries.c

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
