# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 14:58:58 by wchen             #+#    #+#              #
#    Updated: 2023/11/05 19:41:41 by wchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

UNAME			=	$(shell uname)
# CC and CFLAGS
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP
# -fsanitize=address

#IFLAGS
INCLUDES_DIR	=	./includes
IFLAGS			=	-I$(INCLUDES_DIR) -I$(LIBFT_INC) -I$(MLX_INC)

##libft
LIBFT_DIR		=	./libft
LIBFT_INC		=	./libft/includes
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

#cub3d
SRC_DIR			=	./srcs
SRC				=	ft_error.c				\
					main.c					\
					validation.c			\
					fd_check.c				\
					line_check.c			\
					line_judge.c			\
					create_map_array.c		\
					identifier_judge.c		\
					add_img_lst.c			\
					add_color_lst.c			\
					wall_check.c			\
					mlx_initial.c			\
					key_hook.c				\
					destory_hook.c			\
					free_all.c				\
					free_graph.c			\
					ft_lst_free.c			\
					wall_bfs_check.c		\
					edge_initial.c			\
					bfs_check.c				\
					debug/debug_printf.c	\
					rgb_atoi.c        \
					start.c

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR			=	./objs
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

DEPS			=	$(SRC:%.c=%.d)

all: libft_make mlx_make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $$(dirname $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

libft_make:
	make -C $(LIBFT_DIR)

mlx_make:
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f ${MAIN_OBJ}
	rm -rf ${OBJ_DIR}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

re: fclean all

norm:
	@norminette -v
	norminette $(LIBFT_DIR) $(INCLUDES_DIR) $(SRC_DIR)

.PHONY: all clean fclean re norm

-include	$(DEPS)