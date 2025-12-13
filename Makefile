# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 17:58:06 by ttiprez           #+#    #+#              #
#    Updated: 2025/12/13 15:27:25 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Regles Makefile
MAKEFLAGS += -s

# Compilateur et flags
CC			= cc
CFLAGS		= -Wall -Wextra -g -I$(HEADERS_DIR) -I$(PRINTF_DIR)/include -I$(LIBFT_DIR)

# Nom de l'executable
NAME		= pipex

# Dossiers
SRC_DIR		= src
OBJ_DIR		= obj
HEADERS_DIR	= include
	
# ft_printf
PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# libft
LIBFT_DIR	= $(PRINTF_DIR)/libft

# Fichiers sources
SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/parsing/split_quotes.c \
			  $(SRC_DIR)/parsing/split_utils.c \
			  $(SRC_DIR)/parsing/args_check.c \
			  $(SRC_DIR)/parsing/path_parsing.c \
			  $(SRC_DIR)/utils/cmd_list.c \
			  $(SRC_DIR)/utils/cleanup.c \
			  $(SRC_DIR)/execution/child_exec.c \
			  $(SRC_DIR)/execution/pipe_exec.c \
			  $(SRC_DIR)/files/file_manager.c

# Fichiers objets
OBJS		= $(OBJ_DIR)/main.o \
			  $(OBJ_DIR)/parsing/split_quotes.o \
			  $(OBJ_DIR)/parsing/split_utils.o \
			  $(OBJ_DIR)/parsing/args_check.o \
			  $(OBJ_DIR)/parsing/path_parsing.o \
			  $(OBJ_DIR)/utils/cmd_list.o \
			  $(OBJ_DIR)/utils/cleanup.o \
			  $(OBJ_DIR)/execution/child_exec.o \
			  $(OBJ_DIR)/execution/pipe_exec.o \
			  $(OBJ_DIR)/files/file_manager.o

# Couleur
RED			= \033[0;31m
GREEN		= \033[0;32m
CYAN		= \033[0;36m
RESET		= \033[0m

# Regles
all: $(NAME)

# Creer les dossiers objets
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/execution
	@mkdir -p $(OBJ_DIR)/files

# Compiler ft_printf
$(PRINTF):
	@make -C $(PRINTF_DIR) && echo "$(GREEN)[OK] Compilation ft_printf réussie$(RESET)" || (echo "$(RED)[FAIL] Compilation ft_printf échouée$(RESET)"; exit 1)

# Compiler les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Creer l'executable
$(NAME): $(PRINTF) $(OBJS)
	@$(CC) $(OBJS) $(PRINTF) -o $(NAME) && echo "$(GREEN)[OK] Compilation réussie, exécutable créé$(RESET)" || (echo "$(RED)[FAIL] Compilation échouée$(RESET)"; exit 1)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(PRINTF_DIR) clean
	@echo "$(CYAN)Fichiers objets supprimés$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@echo "$(CYAN)Exécutable supprimé$(RESET)"

re: fclean all

.PHONY: all clean fclean re