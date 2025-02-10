# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 16:36:01 by jgasparo          #+#    #+#              #
#    Updated: 2023/11/16 12:15:10 by jgasparo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PREFIX = sources

INC_PREFIX = include

SRC = main.c \
		check.c \
		map.c \
		windows.c \
		bresenham.c \
		error.c \

OBJ = $(addprefix $(SRC_PREFIX)/, $(SRC:.c=.o))
REMOVE = rm -f
CC = gcc

%.o: %.c
	$(CC)  -Imlx -I$(INC_PREFIX) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;33mMiniLibx Compilation in progress...\033[0m"
	@make -C mlx
	@echo "\033[1;32mMiniLibx Compilation done !\033[0m"
	@make -C libft
	$(CC) $(OBJ) -lm -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[1;32mFDF Compilation done !\033[0m"
clean:
	@$(REMOVE) $(OBJ)
	@echo "\033[1;32mFDF Object files cleaned !\033[0m"
	@make clean -C mlx
	@echo "\033[1;32mMiniLibx Object files cleaned !\033[0m"
	@make clean -C libft

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "\033[1;32mFDF Executable cleaned !\033[0m"
	@make clean -C mlx
	@echo "\033[1;32mMiniLibx Library cleaned cleaned !\033[0m"
	@make clean -C libft

re: fclean all

libft:
	make -C libft

mlx:
	make -C mlx

.PHONY: all clean fclean re libft mlx 