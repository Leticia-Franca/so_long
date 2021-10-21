# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 09:14:36 by lfranca-          #+#    #+#              #
#    Updated: 2021/10/19 19:28:00 by lfranca-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
MLX		=	mlx/libmlx.a
LFT		=	libft/libft.a
INC		=	-I ./inc -I ./libft/ -I ./mlx/ -I ./headers
LIB		=	-L ./libft/ -lft -L ./mlx/ -lmlx -lXext -lX11 -lm -lbsd
SRC		=	./src/check_map.c \
			./src/drawing_map.c \
			./src/get_next_line.c \
			./src/hooks.c \
			./src/main.c \
			./src/parse_map.c \
			./src/so_long.c \

OBJ		=	$(SRC:.c=.o)

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
	@make -s -C mlx
	@echo "Minilibx compiled!"

$(LFT):	
	@make -s -C libft
	@echo "Libft compiled!"

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@make -s $@ -C libft
	@rm -rf $(OBJ)
	@echo "object files removed."

fclean:		clean
	@make -s $@ -C libft
	@make -s clean -C mlx
	@rm -rf $(NAME)
	@echo "binary file removed."

re:		fclean all

.PHONY:		all clean fclean re
