# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 14:58:58 by wchen             #+#    #+#              #
#    Updated: 2024/02/08 23:07:57 by wchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
BONUS_NAME		=	cub3D_bonus

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

#source directory
SRC_DIR			=	./srcs
#source
SRC				=	ft_error.c					\
					main.c						\
					validation.c				\
					fd_check.c					\
					line_check.c				\
					line_judge.c				\
					create_map_array.c			\
					identifier_judge.c			\
					add_img_lst.c				\
					add_color_lst.c				\
					wall_check.c				\
					mlx_initial.c				\
					key_hook.c					\
					destory_hook.c				\
					free_all.c					\
					free_graph.c				\
					ft_lst_free.c				\
					wall_bfs_check.c			\
					edge_initial.c				\
					bfs_check.c					\
					rgb_atoi.c					\
					debug/debug_printf.c		\
					debug/cont_debug_printf.c	\
					draw_util/clear.c			\
					draw_util/imageline_utils.c	\
					draw_util/imageline.c		\
					draw_util/init_point.c		\
					draw_util/key_notify.c		\
					draw_util/make_window.c		\
					draw_util/repaint.c			\
					character_judge.c			\

#source in all path
SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))

#obj directory
OBJ_DIR			=	./objs
#object file
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
#dependence file
DEPS			=	$(SRC:%.c=%.d)

#bonus directory
BONUS_DIR		=	./srcs/bonus

#bonus source
#####add file here ######
BONUS_SRC		=				\


#####add file here ######

#bonus source in all path
BONUS_SRCS		=	$(addprefix $(BONUS_DIR)/, $(BONUS_SRC))
# bonus obj directory
BONUS_OBJ_DIR	=	./objs/bonus
# bonus object file
BONUS_OBJS		=	$(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_SRC))
#dependence obj file
BONUS_DEPS		=	$(BONUS_SRC%.c=%.d)

all: libft_make mlx_make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

bonus: libft_make mlx_make $(BONUS_NAME)

$(BONUS_NAME): $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(BONUS_OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

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
	rm -f ${BONUS_NAME}

re: fclean all

norm:
	@norminette -v
	norminette $(LIBFT_DIR) $(INCLUDES_DIR) $(SRC_DIR)

.PHONY: all clean fclean re norm

-include	$(DEPS)
-include	$(BONUS_DEPS)