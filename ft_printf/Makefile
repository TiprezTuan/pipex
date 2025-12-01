# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 13:52:01 by ttiprez           #+#    #+#              #
#    Updated: 2025/11/29 19:01:44 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Regles Makefile
MAKEFLAGS += -s

# Compilateur et flag
CC			= cc
FLAGS		= -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR)

# Nom de l'executable
NAME		= libftprintf.a

# Fichiers sources & objets
SRCS		= ft_printf.c utils.c
OBJS		= $(SRCS:.c=.o)

# libft
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Regles
all: $(NAME)

# Compiler libft d'abord
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Créer libftprintf.a
$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re