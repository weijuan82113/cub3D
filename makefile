# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 14:58:58 by wchen             #+#    #+#              #
#    Updated: 2023/09/23 15:40:13 by wchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

UNAME			=	$(shell uname)
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror \
					-I$(INCLUDES_DIR) -I$(LIBFT_INC) -I$(MLX_INC)
MAIN			=	./main.c
MAIN_OBJ		=	$(MAIN:.c=.o)

INCLUDES_DIR	=	./includes

##libft
LIBFT_DIR		=	./libft
LIBFT_INC		=	$(LIBFT_DIR)
LIBFT_LIB		=	-L $(LIBFT_DIR) -lft

##minilibx
MLX_DIR			=	./minilibx-linux
MLX_INC			=	$(MLX_DIR)
ifeq ($(UNAME), Darwin)
MLX_LIB			=	-L $(MLX_DIR) -lmlx_$(UNAME) -L/usr/X11R6/lib -lX11 -lXext -lm	\
						 -framework OpenGL -framework AppKit
else
MLX_LIB			=	-L $(MLX_DIR) -lmlx_$(UNAME) -L/usr/X11R6/lib -lX11 -lXext -lm
endif


all: libft_make mlx_make $(NAME)

$(NAME): $(MINILIBX) $(MAIN_OBJ) $(SL_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(SL_OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

bonus: libft_make mlx_make $(BONUS_NAME)

$(BONUS_NAME): $(MINILIBX) $(MAIN_OBJ) $(SL_BONUS_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(SL_BONUS_OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

libft_make:
	make -C $(LIBFT_DIR)

mlx_make:
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f ${MAIN_OBJ}
	rm -f ${SL_OBJS}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME} $(BONUS_NAME)

re: fclean all

norm:
	@norminette -v
	norminette $(LIBFT_DIR) $(INCLUDES_DIR) $(SL_DIR)