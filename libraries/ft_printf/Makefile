#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csinglet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:59:57 by csinglet          #+#    #+#              #
#    Updated: 2018/11/09 23:25:49 by csinglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -O3
FLAGS			= $(CFLAGS)

PRINTF_FILES	= ft_printf.c \
				  parsing.c \
				  padding.c padding_helpers.c \
				  handle_ascii.c handle_wascii.c \
				  handle_signed.c \
				  handle_unsigned.c \
				  utils.c \
				  buffer.c

LIBFT_FILES		= ft_abs.c \
				  ft_atoi.c \
				  ft_bzero.c \
				  ft_isdigit.c \
				  ft_lltoa_base.c \
				  ft_llutoa_base.c \
				  ft_memcpy.c \
				  ft_memset.c \
				  ft_numlen.c \
				  ft_strcmp.c \
				  ft_strdup.c \
				  ft_strcpy.c \
				  ft_strlen.c \
				  ft_strndup.c \
				  ft_strnew.c \
				  ft_tolower.c

FILES			= $(PRINTF_FILES) $(LIBFT_FILES)

PF_SRC			= $(addprefix srcs/printf_srcs, $(PRINTF_FILES))
LIB_SRC			= $(addprefix srcs/libft_srcs, $(LIBFT_FILES))
OBJ				= $(addprefix build/, $(FILES:.c=.o))

all: $(NAME)

ft:
	@make -C libft
	@make re

test:
	@$(CC) $(FLAGS) main.c libftprintf.a $(NAME) -o printf -I includes

$(NAME): $(OBJ)
	@echo "Creating archive: $(NAME)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

build:
	@echo "Creating build directory"
	@mkdir build

build/%.o: srcs/*/%.c | build
	@echo "  Building $@"
	@$(CC) $(FLAGS) -I includes -c $< -o $@

clean:
	@rm -fr build

fclean: clean
	@rm -f $(NAME)

re: fclean all
