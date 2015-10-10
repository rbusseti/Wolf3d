#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 16:59:30 by rbusseti          #+#    #+#              #
#    Updated: 2014/10/12 19:14:45 by rbusseti         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = list/ft_create_elem.c \
	list/ft_delete_link.c \
	list/ft_list_push_back.c \
	get_next_line.c \
	ft_strjoin_char.c \
	ft_tputs_putchar.c \
	ft_strdup_gnl.c \
	ft_strjoin_gnl.c \
	ft_itoa.c \
	ft_strsplit.c \
	ft_strtrim.c \
	ft_strjoin.c \
	ft_strsub.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strmapi.c \
	ft_strmap.c \
	ft_striteri.c \
	ft_striter.c \
	ft_strclr.c \
	ft_strdel.c \
	ft_strnew.c \
	ft_memdel.c \
	ft_memalloc.c \
	ft_putnbr_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_putchar_fd.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_memccpy.c \
	ft_memcpy.c \
	ft_bzero.c \
	ft_memset.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isupper.c \
	ft_putchar.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_atoi.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(FLAGS) -c -o $@ $^ -I includes/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re name clean fclean