/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:20 by wchen             #+#    #+#             */
/*   Updated: 2023/10/11 21:09:20 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx-linux/mlx.h"
#include "error_msg.h"
#include "libft.h"
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>

/* ************************** */
/*         struct             */
/* ************************** */
typedef struct s_img
{
	char			*obj;
	char			*img_path;
	struct s_img	*next;
}				t_img;

typedef struct	s_map_info
{
	int			w;
	int			h;
}				t_map_info;


typedef struct				s_g_board
{
	t_node					*line_lst;
	t_img					*img_lst;
	t_map_info				*m_info;
	int x;
	int y;
	int t_count;
	int m_count;
}							t_g_board;


/* ************************** */
/*         function           */
/* ************************** */

void test(void);
bool validation(int argc, char **argv);
bool fd_check(int fd);
bool line_check(char* line, t_g_board *g_board);
bool line_judge(t_g_board *g_board, char *line);
bool create_map_array(t_g_board *g_board);
bool identifier_judge(t_g_board *g_board, char *line);
bool add_id_lst(t_g_board *g_board, char** split);

/*Error*/
bool	ft_error(char *err_msg);




#endif