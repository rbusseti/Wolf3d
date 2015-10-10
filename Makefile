NAME = test

SRC = main.c init.c loop_hook.c update.c draw.c keyboard.c \
	expose_hook.c mouse_hook.c move_character.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra

INC = -I Headers/ -I libft/includes/

LIB = -L ../minilibx/ -L libft/ -lft -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LIB) $(INC)

%.o:%.c
	$(CC) $(FLAGS) -c -o $@ $^ $(INC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all