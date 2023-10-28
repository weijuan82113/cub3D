/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:20 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 20:52:42 by kitsuki          ###   ########.fr       */
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

typedef struct s_bfs
{
	t_queue			*q;
	int				*start_vertex;
	int				current_vertex;
	t_node			*temp;
	int				*adj_vertex;
}					t_bfs;

typedef struct s_graph
{
	int				num_vertex;
	t_node			**adj_lsts;
	int				*visited;
}					t_graph;

typedef struct s_img
{
	char			*obj;
	char			*img_path;
	void			*p_img;
	int				h;
	int				w;
	struct s_img	*next;
}				t_img_node;

typedef struct s_color
{
	char			*obj;
	char			*rbg;
	struct s_color	*next;
}			t_color_node;


typedef struct	s_map_info
{
	char		**map;
	int			*h;//heigh of map
	int			*w;//width of map
}				t_map_info;

typedef struct				s_g_board
{
	t_node					*line_lst;//save the line readed from getline
	t_img_node				*img_lst;//sava the img_obj;
	t_color_node			*color_lst;//sava the color_obj;
	t_map_info				*m_info;//map info
	int						*p_position;//player position
	int 					t_count;//the identifier amount count
}							t_g_board;

typedef struct				s_mlx
{
	void		*p_mlx;
	void		*p_win;
	t_g_board	*g;
}							t_mlx;

/* ************************** */
/*         function           */
/* ************************** */

void	test(void);
t_mlx	*mlx_initial(void);
bool	validation(t_mlx *mlx, int argc, char **argv);
bool	fd_check(t_mlx *mlx, int fd);
bool	line_check(char* line, t_mlx *mlx, int *x, int *y);
bool	line_judge(t_g_board *g_board, char *line, int *x, int *y);
bool	create_map_array(t_g_board *g_board);
bool 	wall_check(t_node *line_lst, int h);
bool	identifier_judge(t_mlx *mlx, char *line);
bool	add_img_lst(t_mlx *mlx, char** split);
bool	add_color_lst(t_mlx *mlx, char** split);
int		key_hook(int keycode, t_mlx *mlx);
int		destroy_hook(t_mlx *mlx);
/*Error*/
bool	ft_error(char *err_msg);

#endif