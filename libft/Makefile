# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/04 19:22:36 by alelievr          #+#    #+#              #
#    Updated: 2023/10/28 17:22:29 by wchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

#	CC CFLAGS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP

#	DIRS
LIB_DIR		= ./lib
GNL_DIR		= ./gnl
OBJ_DIR		= ./objs

#	Sources
LIBFT_SRC		=ft_lstmap.c					\
				ft_lstiter.c					\
				ft_lstclear.c					\
				ft_lstdelone.c					\
				ft_lstadd_back.c				\
				ft_lstlast.c					\
				ft_lstsize.c					\
				ft_lstadd_front.c				\
				ft_lstnew.c						\
				ft_strmapi.c					\
				ft_striteri.c					\
				ft_putchar_fd.c					\
				ft_putstr_fd.c					\
				ft_putendl_fd.c					\
				ft_putnbr_fd.c					\
				ft_substr.c						\
				ft_strtrim.c					\
				ft_strjoin.c					\
				ft_strdup.c						\
				ft_split.c						\
				ft_itoa.c						\
				ft_calloc.c						\
				ft_atoi.c						\
				ft_memchr.c						\
				ft_memcmp.c						\
				ft_strchr.c						\
				ft_strncmp.c					\
				ft_strnstr.c					\
				ft_strrchr.c					\
				ft_tolower.c   					\
				ft_toupper.c           			\
				ft_bzero.c						\
				ft_isalnum.c					\
				ft_isalpha.c					\
				ft_isascii.c					\
				ft_isdigit.c					\
				ft_isstrempty.c					\
				ft_isprint.c					\
				ft_memcpy.c						\
				ft_memmove.c					\
				ft_memset.c						\
				ft_strlcat.c 					\
				ft_strlcpy.c					\
				ft_strlen.c						\
				ft_strlen_ntr.c					\
				ft_printf.c						\
				print_bx.c						\
				print_char.c					\
				print_int.c						\
				print_ptr.c						\
				print_str.c						\
				print_unint.c					\
				print_x.c						\
				ft_create_queue.c				\
				ft_dequeue.c					\
				ft_enqueue.c					\
				ft_lst_ascsort.c				\
				ft_lst_descsort.c				\
				ft_cut_tr.c

GNL_SRC			=get_next_line.c				\
				get_next_line_utils.c

SRCS			= $(addprefix $(LIB_DIR)/, $(LIBFT_SRC)) \
				$(addprefix $(GNL_DIR)/, $(GNL_SRC))

#	Objects
OBJ		= $(SRCS:%.c=%.o)
OBJS	= $(addprefix $(OBJ_DIR)/, $(OBJ))

#	Dependence
DEPS	= $(SRCS:%.c=%.d)

# INCLUDES
INCLUDE_DIR	= ./includes
IFLAGS		= $(addprefix -I, $(INCLUDE_DIR))

# RULES

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}
	#$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o	:%.c
	@mkdir -p $$(dirname $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all:		${NAME}

clean:
			rm -rf ${OBJ_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

-include	$(DEPS)