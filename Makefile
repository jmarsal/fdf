# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 00:34:02 by jmarsal           #+#    #+#              #
#    Updated: 2016/09/22 09:29:57 by jmarsal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
OPTI = -O3
CFLAGS_DEBUG = -g3 -O0 -fsanitize=address
CFLAGS = -Wall -Werror -Wextra $(OPTI)
SRC_DIR = ./srcs/
SRC_FILES = main.c init_app.c event.c draw.c perror.c get_data.c mlx_start.c \
			init_data.c size_win.c affine.c draw_tools.c init_size_win.c \
			key_funct.c print_strings.c change_map.c
OBJ_PATH = ./obj
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_PATH)/%.o)
INC_PATH = -I./libmlx/ -I./libft/includes/ -I./includes/
LIB_PATH = -L./libft/ -lft -L./libmlx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
$(NAME): $(OBJ_FILES)
	@make -C libmlx
	@make -C libft
	@$(CC) -o $(NAME) $(OBJ_FILES) $(CFLAGS) $(INC_PATH) $(LIB_PATH)
	@echo "\n-----------------------------------------"
	@echo "|\033[32;1m\t$(NAME) has been created !\t\t\033[0m|"
	@echo "-----------------------------------------\n"

$(OBJ_PATH)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\n-------------------------------------------------"
	@echo "|\t\033[31mall $(NAME) files.o are deleted\033[0m\t\t|"
	@echo "-------------------------------------------------\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\n---------------------------------"
	@echo "|\t\033[31m$(NAME) is deleted\033[0m\t\t|"
	@echo "---------------------------------\n"

re: fclean all

libs:
	@make -C libft
	@make -C libmlx

libs-clean:
	@make -C libft clean
	@make -C libmlx clean

libs-fclean:
	@make -C libft fclean
	@make -C libmlx clean

libs-re: libs-fclean
	@make -C libft re
	@make -C libmlx re

fclean-all: fclean libs-fclean

debug: CFLAGS := $(filter-out $(OPTI),$(CFLAGS) $(CFLAGS_DEBUG))
debug: re
	@echo "\n-----------------------------------------------------------------"
	@echo "|\033[32;1m\tDebug mode for $(NAME) with $(CFLAGS_DEBUG)!\t\033[0m|"
	@echo "-----------------------------------------------------------------\n"

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY:  all, clean, fclean, re, libs, libs-clean, libs-fclean, libs-re \
		fclean-all, debug, norme
