# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 15:47:54 by ttiprez           #+#    #+#              #
#    Updated: 2025/11/29 20:54:48 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Regles Makefile
MAKEFLAGS += -s

# Compilateur et flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Commandes
RM			= rm -f
AR			= ar rcs

# Nom de la librairie
NAME		= libft.a

# Fichiers sources
SRCS		= ft_atoi.c				\
			  ft_atol.c				\
			  ft_bzero.c			\
			  ft_calloc.c			\
			  ft_isalnum.c			\
			  ft_isalpha.c			\
			  ft_isascii.c			\
			  ft_isdigit.c			\
			  ft_isprint.c			\
			  ft_itoa.c				\
			  ft_memchr.c			\
			  ft_memcmp.c			\
			  ft_memcpy.c			\
			  ft_memmove.c			\
			  ft_memset.c			\
			  ft_putchar_fd.c		\
			  ft_putendl_fd.c		\
			  ft_putnbr.c			\
			  ft_putnbr_fd.c		\
			  ft_putstr_fd.c		\
			  ft_split.c			\
			  ft_strcat.c			\
			  ft_strchr.c			\
			  ft_strcmp.c			\
			  ft_strcpy.c			\
			  ft_strdup.c			\
			  ft_striteri.c			\
			  ft_strjoin.c			\
			  ft_strlcat.c			\
			  ft_strlcpy.c			\
			  ft_strlen.c			\
			  ft_strmapi.c			\
			  ft_strncat.c			\
			  ft_strncmp.c			\
			  ft_strncpy.c			\
			  ft_strnstr.c			\
			  ft_strrchr.c			\
			  ft_strstr.c			\
			  ft_substr.c			\
			  ft_strtrim.c			\
			  ft_tolower.c			\
			  ft_toupper.c			\

# Fichiers sources bonus
BONUS_SRCS	= ft_lstadd_back.c		\
			  ft_lstadd_front.c		\
			  ft_lstclear.c			\
			  ft_lstdelone.c		\
			  ft_lstiter.c			\
			  ft_lstlast.c			\
			  ft_lstmap.c			\
			  ft_lstnew.c			\
			  ft_lstsize.c			\

# Fichiers objets
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

# Regles
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@touch .bonus

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME) .bonus

re: fclean all

.PHONY: fclean clean re all bonus