# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 17:58:06 by ttiprez           #+#    #+#              #
#    Updated: 2025/12/03 02:33:32 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Regles Makefile
MAKEFLAGS += -s

# Compilateur et flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I$(HEADERS_DIR) -I$(PRINTF_DIR)/includes -I$(LIBFT_DIR)

# Nom de l'executable
NAME		= pipex

# Fichiers sources & objets
SRCS		= pipex.c
OBJS		= $(SRCS:.c=.o)

# Headers
HEADERS_DIR	= includes
HEADERS		= $(HEADERS_DIR)/pipex.h

# ft_printf
PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# libft
LIBFT_DIR	= $(PRINTF_DIR)/libft

# Couleurs
RED			= \033[0;31m
GREEN		=\033[0;32m
CYAN		=\033[0;36m
RESET		=\033[0m

# Regles
all: $(NAME)

# Compiler ft_printf d'abord
$(PRINTF):
	@make -C $(PRINTF_DIR) && echo "$(GREEN)[OK] Compilation ft_printf réussie$(RESET)" || (echo "$(RED)[FAIL] Compilation ft_printf échouée$(RESET)"; exit 1)

# Creer l'executable
$(NAME): $(PRINTF) $(OBJS)
	@$(CC) $(OBJS) $(PRINTF) -o $(NAME) && echo "$(GREEN)[OK] Compilation réussie, exécutable créé$(RESET)" || (echo "$(RED)[FAIL] Compilation échouée$(RESET)"; exit 1)

clean:
	@rm -f $(OBJS)
	@make -C $(PRINTF_DIR) clean
	@echo "$(CYAN)Fichiers objets supprimés$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@echo "$(CYAN)Exécutable supprimés$(RESET)"

re: fclean all

.PHONY: all clean fclean re