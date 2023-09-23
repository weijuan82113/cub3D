# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/04 19:22:36 by alelievr          #+#    #+#              #
#    Updated: 2022/12/30 18:15:26 by wchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Sources
SRCS			=ft_lstmap.c					\
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
				ft_isprint.c					\
				ft_memcpy.c						\
				ft_memmove.c					\
				ft_memset.c						\
				ft_strlcat.c 					\
				ft_strlcpy.c					\
				ft_strlen.c						\
				get_next_line.c					\
				get_next_line_bonus.c			\
				get_next_line_utils.c			\
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

#	Objects
OBJS		= $(SRCS:%.c=%.o)

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

CC			= cc

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
