# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal  <jmarsal @student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 00:34:02 by jmarsal           #+#    #+#              #
#    Updated: 2016/05/27 23:09:46 by jmarsal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = ./srcs/
SRC_FILES = main.c init.c event.c draw.c
OBJ_PATH = ./obj
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_PATH)/%.o)
INC_PATH = -I./libft/ -I./libmlx/ -I./includes/
LIB_PATH = -L./libmlx/ -lmlx -L./libft/ -lft -framework OpenGL -framework AppKit

all: make

make: libs $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C libft
	@make -C libmlx
	$(CC) -o $(NAME) $(OBJ_FILES) $(CFLAGS) $(INC_PATH) $(LIB_PATH)

$(OBJ_PATH)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC_PATH)
	@echo "\n-------------------------------------------------"
	@echo "|\033[32;1m\t\t$(NAME) has been created !\t\t\033[0m|"
	@echo "-------------------------------------------------\n"

clean:
	rm -rf $(OBJ_PATH)
	@echo "\n-------------------------------------------------"
	@echo "|\t\033[31mall $(NAME) files.o are deleted\033[0m\t\t|"
	@echo "-------------------------------------------------\n"

fclean: clean
	rm -f $(NAME)
	@echo "\n---------------------------------"
	@echo "|\t\033[31m$(NAME) is deleted\033[0m\t\t|"
	@echo "---------------------------------\n"

re: fclean all

libs:
	make -C libft
	make -C libmlx

libs-clean:
	make -C libft clean
	make -C libmlx clean

libs-fclean: libs-clean
	make -C libft fclean

libs-re: libs-fclean
	make -C libft re
	make -C libmlx re

fclean-all: fclean libs-fclean

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY:  all, clean, fclean, re