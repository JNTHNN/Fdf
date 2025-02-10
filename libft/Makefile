# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 11:07:53 by jgasparo          #+#    #+#              #
#    Updated: 2023/11/13 09:12:50 by jgasparo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC_PREFIX = sources

INC_PREFIX = includes

SRC = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_strchr.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_striteri.c \
ft_split.c \
ft_itoa.c \
ft_lstnew_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstmap_bonus.c \
ft_lstiter_bonus.c \
get_next_line.c \
get_next_line_utils.c \

OBJ = $(addprefix $(SRC_PREFIX)/, $(SRC:.c=.o))

CFLAGS = -Wall -Werror -Wextra -I $(INC_PREFIX)

LIB  = ar rcs $(NAME) 

REMOVE = rm -f

all: $(NAME)

$(NAME):	$(OBJ)
	@echo "\033[1;33mLIBFT Compilation in progress...\033[0m"
	@$(LIB) $(OBJ)
	@echo "\033[1;32mLIBFT Compilation done !\033[0m"

clean:
	@$(REMOVE) $(OBJ)
	@echo "\033[1;32mLIBFT Object Files cleaned !\033[0m"

fclean:	clean
	@$(REMOVE) $(NAME)
	@echo "\033[1;32mLIBFT Library cleaned !\033[0m"

re: fclean all

.PHONY: all clean fclean re