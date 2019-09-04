# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csinglet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:59:57 by csinglet          #+#    #+#              #
#    Updated: 2019/02/08 14:35:41 by csinglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RTv1

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O3 -lpthread
FLAGS		= $(CFLAGS)

FILES		= main.c

FRAMEWORKS	= -framework OpenGL -framework Appkit

ALL_FILES	= $(FILES) $(LX_FILES) $(CLINE_FILES) $(GLOB_FILES)

OBJ			= $(addprefix build/, $(ALL_FILES:.c=.o))

INC_FT		= -I libraries/libft/includes
LINK_FT		= -L libraries/libft -lft
FT			= $(INC_FT) $(LINK_FT)

INC_PF		= -I libraries/ft_printf/includes
LINK_PF		= -L libraries/ft_printf -lftprintf
PF			= $(INC_PF) $(LINK_PF)

INC_MLX		= -I libraries/minilibx
LINK_MLX	= -L libraries/minilibx -lmlx
MLX			= $(INC_MLX) $(LINK_MLX)

INC_DRAW	= -I libraries/draw/includes
LINK_DRAW	= -L libraries/draw -ldraw
DRAW		= $(INC_DRAW) $(LINK_DRAW)

LIBS		= $(FT) $(PF) $(MLX) $(DRAW)
INC_LIBS	= $(INC_FT) $(INC_PF) $(INC_MLX) $(INC_DRAW)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libraries/minilibx
	@make -C libraries/draw
	@make -C libraries/libft
	@make -C libraries/ft_printf
	@echo "Creating: $(NAME)"
	@$(CC) $(FLAGS) $(LIBS) $(FRAMEWORKS) -I includes $(OBJ) -o $@

build:
	@echo "Creating build directory"
	@mkdir build

build/%.o: sources/%.c | build
	@echo "  Building $@"
	@$(CC) $(INC_LIBS) -I includes -c $< -o $@

clean:
	@rm -fr build
	@make clean -C libraries/minilibx
	@make clean -C libraries/libft
	@make clean -C libraries/ft_printf
	@make clean -C libraries/draw

fclean: clean
	@rm -f $(NAME)
	@make clean -C libraries/minilibx
	@make fclean -C libraries/libft
	@make fclean -C libraries/ft_printf
	@make fclean -C libraries/draw

re: fclean all
