# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 15:19:59 by jmarsal           #+#    #+#              #
#*   Updated: 2016/04/26 00:19:32 by jmarsal          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I./includes/
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
	ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_itoa_base.c ft_print_memory.c \
	ft_isupper.c ft_islower.c ft_isspace.c ft_strnlen.c ft_strtoupper.c \
	ft_strtolower.c ft_abs.c ft_min.c ft_max.c

OBJ = $(SRC:%.c=%.o)

HEADER = header.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INC)

clean:
	rm -f $(OBJ) libft.h.gch a.out

fclean: clean
	rm -f $(NAME)

re: fclean all
