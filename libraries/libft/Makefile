# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csinglet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:59:57 by csinglet          #+#    #+#              #
#    Updated: 2018/09/13 20:27:33 by csinglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

FILES		= ft_memset.c\
			  ft_bzero.c\
			  ft_memcpy.c\
			  ft_memccpy.c\
			  ft_memmove.c\
			  ft_memchr.c\
			  ft_memcmp.c\
			  ft_strlen.c\
			  ft_strdup.c\
			  ft_strcpy.c\
			  ft_strncpy.c\
			  ft_strcat.c\
			  ft_strncat.c\
			  ft_strlcat.c\
			  ft_strchr.c\
			  ft_strrchr.c\
			  ft_strstr.c\
			  ft_strnstr.c\
			  ft_strcmp.c\
			  ft_strncmp.c\
			  ft_atoi.c\
			  ft_isalpha.c\
			  ft_isdigit.c\
			  ft_isalnum.c\
			  ft_isascii.c\
			  ft_isprint.c\
			  ft_issquare.c\
			  ft_toupper.c\
			  ft_tolower.c\
			  ft_memalloc.c\
			  ft_memdel.c\
			  ft_realloc.c\
			  ft_strnew.c\
			  ft_strdel.c\
			  ft_strclr.c\
			  ft_striter.c\
			  ft_striteri.c\
			  ft_strmap.c\
			  ft_strmapi.c\
			  ft_strequ.c\
			  ft_strnequ.c\
			  ft_strsub.c\
			  ft_strjoin.c\
			  ft_strjoin_free.c\
			  ft_strjoin_free_s1.c\
			  ft_strjoin_free_s2.c\
			  ft_strtrim.c\
			  ft_strsplit.c\
			  ft_itoa.c\
			  ft_putchar.c\
			  ft_putstr.c\
			  ft_putendl.c\
			  ft_putnbr.c\
			  ft_putchar_fd.c\
			  ft_putstr_fd.c\
			  ft_putendl_fd.c\
			  ft_putnbr_fd.c\
			  ft_lstnew.c\
			  ft_lstdelone.c\
			  ft_lstdel.c\
			  ft_lstadd.c\
			  ft_lstiter.c\
			  ft_lstmap.c\
			  ft_lstadd_end.c\
			  ft_pow.c\
			  ft_numlen.c\
			  ft_lstlen.c\
			  ft_wrdcount.c\
			  ft_realloc_str.c\
			  ft_copy_until.c\
			  get_next_line.c\
			  ft_putspace.c\
			  ft_ascii_cmp.c\
			  ft_sort_list_ascii.c\
			  ft_free_strsplit.c\
			  ft_strndup.c\

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(addprefix build/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating archive: $(NAME)"
	@ar rcs $(NAME) $(OBJ)

build:
	@echo "Creating build directory"
	mkdir build

build/%.o: srcs/%.c | build
	@echo "  Building $@"
	@$(CC) $(FLAGS) -I includes -c $< -o $@

clean:
	@rm -fr build

fclean: clean
	@rm -f $(NAME)

re: fclean all
