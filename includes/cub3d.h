/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:20 by wchen             #+#    #+#             */
/*   Updated: 2023/11/02 23:03:22 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "properties.h"
# include "libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

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
	void			*path;
	int				bpp;
	int				length;
	int				endian;
	struct s_img	*next;
}				t_img_node;

typedef struct s_color
{
	char			*obj;
	char			*rgb;
	int				rgb_int;
	struct s_color	*next;
}			t_color_node;

typedef struct s_map_info
{
	char		**map;
	int			*h;
	int			*w;
}				t_map_info;

typedef struct s_g_board
{
	t_node					*line_lst;
	t_img_node				*img_lst;
	t_color_node			*color_lst;
	t_map_info				*m_info;
	int						*p_position;
	int						t_count;
}							t_g_board;

typedef struct s_mlx
{
	void		*p_mlx;
	void		*p_win;
	void		*image;
	int bpp;
	int length;
	int endian;
	void *path;
	t_g_board	*g;
}				t_mlx;

/* ************************** */
/*         function           */
/* ************************** */

void	draw(t_mlx *mlx);
void	test(void);
t_mlx	*mlx_initial(void);
bool	validation(t_mlx *mlx, int argc, char **argv);
bool	fd_check(t_mlx *mlx, int fd);
bool	line_check(char *line, t_mlx *mlx, int *x, int *y);
bool	line_judge(t_g_board *g_board, char *line, int *x, int *y);
bool	create_map_array(t_g_board *g_board);
bool	wall_check(t_node *line_lst, int h);
bool	identifier_judge(t_mlx *mlx, char *line);
bool	add_img_lst(t_mlx *mlx, char **split);
bool	add_color_lst(t_mlx *mlx, char **split);
int		key_hook(int keycode, t_mlx *mlx);
int		destroy_hook(t_mlx *mlx);
void	free_all(t_mlx *mlx);
void	free_split(char **split);
void	free_graph(t_graph *graph);
void	ft_colorlstclear(t_color_node **lst, void (*del)(void*));
void	ft_imglstclear(t_img_node **lst, void (*del)(void*));
int		rgb_atoi(char *rgb);

/*Error*/
bool	ft_error(char *err_msg);
bool	wall_bfs_check(t_g_board *g);
bool	edge_initial(t_graph *graph, t_g_board *g);
bool	bfs_check(t_graph *graph, int start, bool result);
//debug
void	debug_print_map_array(char **map);
void	print_vidited(int *visited, int size, int x);
void	print_graph(t_graph *graph);
void	debug_print_linelst(t_g_board *g_board);
void	debug_print_colorlst(t_color_node *color_lst);
void	debug_print_imglst(t_img_node *img_lst);

#endif