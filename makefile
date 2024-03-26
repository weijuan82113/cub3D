# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 14:58:58 by wchen             #+#    #+#              #
#    Updated: 2024/03/27 02:53:26 by wchen            ###   ########.fr        #
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

VPATH			=	$(SRC_DIR)

#source directory
SRC_DIR			=	./srcs
#source
SRC				=	ft_error					\
					main						\
					validation					\
					fd_check					\
					line_check					\
					line_judge					\
					create_map_array			\
					identifier_judge			\
					add_img_lst					\
					add_color_lst				\
					wall_check					\
					mlx_initial					\
					key_hook					\
					destory_hook				\
					free_all					\
					free_graph					\
					ft_lst_free					\
					wall_graph_check			\
					edge_initial				\
					graph_check					\
					rgb_atoi					\
					debug/debug_printf			\
					debug/cont_debug_printf		\
					draw_util/clear				\
					draw_util/imageline_utils	\
					draw_util/imageline			\
					draw_util/init_point		\
					draw_util/key_notify		\
					draw_util/make_window		\
					draw_util/repaint			\
					character_judge				\

#the suffix of bonus
C_SUFFIX		=	.c
SRC_C			=	$(addsuffix $(C_SUFFIX), $(SRC))
#source in all path
SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC_C))
#obj directory
OBJ_DIR			=	./objs
#object file
OBJ				=	$(SRCS:%.c=%.o)
#object files with path
OBJS			=	$(addprefix $(OBJ_DIR)/, $(OBJ))
#dependence file
DEPS			=	$(OBJS:%.o=%.d)

#bonus directory
BONUS_DIR		=	./srcs/bonus
#the suffix of bonus
BONUS_SUFFIX	=	_bonus.c
#bonus source
BONUS_SRC		=	$(addsuffix $(BONUS_SUFFIX), $(SRC))
#bonus source in all path
BONUS_SRCS		=	$(addprefix $(BONUS_DIR)/, $(BONUS_SRC))
# bonus obj directory
BONUS_OBJ_DIR	=	./objs/bonus
# bonus object file
BONUS_OBJ		=	$(BONUS_SRCS:%.c=%.o)
# bonus object files with path
BONUS_OBJS		=	$(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_OBJ))
#dependence obj file
BONUS_DEPS		=	$(BONUS_OBJS%.c=%.d)

all: libft_make mlx_make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

bonus: libft_make mlx_make $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(BONUS_OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

$(OBJ_DIR)/%.o : %.c
	mkdir -p $$(dirname $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o : %.c
	@mkdir -p $$(dirname $@)
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
	rm -rf ${BONUS_OBJ_DIR}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}
	rm -f ${BONUS_NAME}

re: fclean all

norm:
	@norminette -v
	norminette $(LIBFT_DIR) $(INCLUDES_DIR) $(SRC_DIR)

-include	$(DEPS)
-include	$(BONUS_DEPS)

.PHONY: all clean fclean re norm $(DEPS) $(BONUS_DEPS)
