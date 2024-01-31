##
## EPITECH PROJECT, 2022
## B-PSU-100-PAR-1-1-sokoban-damian.gil
## File description:
## Makefile
##

SRC =	delimcheck.c	\
		mysh.c		\
		my_str_to_array.c	\
		proto.c				\
		my_strcat.c			\
		my_array_len.c		\
		check.c				\
		my_strcpy.c			\
		env.c				\
		my_strcmp.c			\
		cd.c				\
		exit.c				\
		my_strdup.c			\
		str_double_del.c	\
		setenv.c			\
		setenv_next.c		\
		parsing.c			\
		cases_parsing.c		\
		empty.c				\
		tree.c 				\
		tree_second.c		\
		execute_tree.c		\
		pipe.c				\
		write.c				\
		read.c				\
		grep.c				\
		my_isalpha.c

OBJ =	$(SRC:.c=.o)

NAME =	mysh

NAME:	all

all:
		gcc $(SRC) -o $(NAME) -g -g3 -Wall

clean:
		rm -f $(NAME) $(OBJ)

fclean: clean
			rm -f $(NAME)

re:		fclean all
