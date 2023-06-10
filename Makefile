NAME = cub3D

SRCS_DIR = ./src
GNL_DIR = ./gnl

SRCS = $(SRCS_DIR)/main.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit \
	-L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c ./libft/libft.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all