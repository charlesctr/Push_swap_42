# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 11:31:19 by chcoutur          #+#    #+#              #
#    Updated: 2019/10/07 13:49:15 by chcoutur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./checker

NAME2 = ./push_swap

FLAGS = -Wall -Wextra -Werror

SRC_FILES = main_checker.c		\
			set.c				\
			check.c				\
			move_p.c			\
			move_r.c			\
			move_rr.c			\
			move_s.c			\
			move.c				\
			check_end.c			\
			utilities.c

SRC_FILES2 = main_push.c		\
			set.c				\
			move_p.c			\
			move_r.c			\
			move_rr.c			\
			move_s.c			\
			move.c				\
			check.c				\
			check_end.c			\
			pivot_data.c		\
			sort.c				\
			sort_next.c			\
			sort_five.c			\
			utilities.c

HEADER_PATH = ./includes/
LIB_PATH = ./libft/
SRC_PATH = ./src/
OBJ_PATH = ./obj/

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

OBJ_FILES2 = $(SRC_FILES2:.c=.o)
	OBJ_EXEC2 = $(addprefix $(OBJ_PATH), $(OBJ_FILES2))

LIB_FILES = libft.a

LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))

all: $(LIB) $(NAME) $(NAME2) 

$(OBJ_PATH):
	mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(HEADER_PATH) -I $(LIB_PATH)includes/
	printf "\033[1;34mCompilation of \033[36m$(notdir $<)\033[0m \033[32mdone\033[0m\n"

$(LIB): .FORCE
	make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC) $(HEADER_PATH)
	gcc $(FLAGS) $(OBJ_EXEC) $(LIB) -o $(NAME) -I $(HEADER_PATH) -I $(LIB_PATH)includes/
	echo "\033[1;32m$(NAME)\t\t\033[0;32m[Compilation done]\033[0;32m"

$(NAME2): $(LIB) $(OBJ_PATH) $(OBJ_EXEC2) $(HEADER_PATH)
	gcc $(FLAGS) $(OBJ_EXEC2) $(LIB) -o $(NAME2) -I $(HEADER_PATH) -I $(LIB_PATH)includes/
	echo "\033[1;32m$(NAME2)\t\t\033[0;32m[Compilation done]\033[0;32m"

clean:
	make clean -C libft/
	/bin/rm -rf $(OBJ_PATH)
	echo "\033[1;32m$(NAME) and $(NAME2)\t\t\033[1;31m[.o removed]"

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME) $(NAME2)
	echo "\033[1;32m$(NAME)\t\t\033[1;31m[Executable removed]"
	echo "\033[1;32m$(NAME2)\t\t\033[1;31m[Executable removed]"

re: fclean all

.FORCE:
.PHONY: all, clean, fclean, re
.SILENT:
