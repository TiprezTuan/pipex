# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 17:58:06 by ttiprez           #+#    #+#              #
#    Updated: 2025/12/07 16:31:07 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Regles Makefile
MAKEFLAGS += -s

# Compilateur et flags
CC			= cc
CFLAGS		=  -Wall -Wextra -Werror -g -I$(HEADERS_DIR) -I$(PRINTF_DIR)/includes -I$(LIBFT_DIR)

# Nom de l'executable
NAME		= pipex

# get_next_line
GNL_DIR		= get_next_line

# Fichiers sources & objets
SRCS		= pipex.c child_process_management.c command_execution.c environment_parsing.c error_handling.c memory_management.c pipes_management.c string_splitting_with_quote_handling.c string_splitting_with_quote_handling_utils.c ft_heredoc.c
OBJS		= $(SRCS:.c=.o)

# Headers
HEADERS_DIR	= includes
HEADERS		= $(HEADERS_DIR)/pipex.h $(HEADERS_DIR)/child_process_management.h $(HEADERS_DIR)/command_execution.h $(HEADERS_DIR)/environment_parsing.h $(HEADERS_DIR)/error_handling.h $(HEADERS_DIR)/memory_management.h $(HEADERS_DIR)/pipes_management.h $(HEADERS_DIR)/string_splitting_with_quote_handling.h $(HEADERS_DIR)/string_splitting_with_quote_handling_utils.h $(GNL_DIR)/get_next_line.h

# ft_printf
PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# libft
LIBFT_DIR	= $(PRINTF_DIR)/libft

# Couleur
RED			= \033[0;31m
GREEN		=\033[0;32m
CYAN		=\033[0;36m
RESET		=\033[0m

# Regles
all: $(NAME)

# Compiler ft_printf
$(PRINTF):
	@make -C $(PRINTF_DIR) && echo "$(GREEN)[OK] Compilation ft_printf réussie$(RESET)" || (echo "$(RED)[FAIL] Compilation ft_printf échouée$(RESET)"; exit 1)

# Compiler get_next_line


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