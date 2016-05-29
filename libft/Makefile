# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 15:19:59 by jmarsal           #+#    #+#              #
#    Updated: 2016/05/25 12:25:25 by jmarsal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
OPTI_FLAGS = -O2
CFLAGS = $(OPTI_FLAGS) -Wall -Wextra -Werror
INC_PATH = -I./includes/
SRC = ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_atoi.c ft_strncmp.c \
	ft_strcmp.c ft_strstr.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strcpy.c \
	ft_strncpy.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isalnum.c \
	ft_isprint.c ft_toupper.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_bzero.c\
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strchr.c ft_strrchr.c \
	ft_strnstr.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
	ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstadd_end.c ft_lstiter.c ft_lstmap.c ft_itoa_base.c \
	ft_print_memory.c ft_isupper.c ft_islower.c ft_isspace.c ft_strnlen.c \
	ft_strtoupper.c ft_strtolower.c ft_abs.c ft_min.c ft_max.c
OBJ_PATH = ./obj
OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\n-----------------------------------------------------------------"
	@echo "|\033[32;1m\t$(NAME) has been created with $(OPTI_FLAGS) optimisation\t\t\033[0m|"
	@echo "-----------------------------------------------------------------\n"

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC_PATH)

clean:
	rm -rf $(OBJ_PATH)
	@echo "\n-------------------------------------------------"
	@echo "|\t\033[31mall libft_files.o are deleted\033[0m\t\t|"
	@echo "-------------------------------------------------\n"

fclean: clean
	rm -f $(NAME)
	@echo "\n-----------------------------------------"
	@echo "|\t\033[31m$(NAME) is deleted\033[0m\t\t|"
	@echo "-----------------------------------------\n"

re: fclean all
