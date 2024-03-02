/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:59:46 by wchen             #+#    #+#             */
/*   Updated: 2024/02/12 21:29:40 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_color_node	*ft_new_colorlst(char *obj, int rgb)
{
	t_color_node	*color;

	color = malloc(sizeof(t_color_node));
	if (!color)
		return (NULL);
	color->obj = ft_cut_tr(obj);
	if (!color->obj)
	{
		free(color);
		return (NULL);
	}
	color->rgb_int = rgb;
	color->next = NULL;
	return (color);
}

static void	ft_colorlstadd_back(t_color_node **head, t_color_node *new)
{
	t_color_node	*tail;

	if (!*head)
		*head = new;
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new;
	}
}

static bool	check_rgb(char *str)
{
	int		i;
	int		comma_num;
	bool	is_before_comma;

	i = 0;
	comma_num = 0;
	is_before_comma = true;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (is_before_comma)
				return (true);
			is_before_comma = true;
			comma_num++;
		}
		else if ('0' <= str[i] && str[i] <= '9')
			is_before_comma = false;
		else if (is_before_comma || str[i] != '\n')
			return (true);
		i++;
	}
	if (comma_num != 2)
		return (true);
	return (false);
}

bool	add_color_lst(t_mlx *mlx, char **split)
{
	int				rgb;
	t_color_node	*new_color;

	errno = 0;
	if (check_rgb(split[1]))
		return (ft_error(COLOR_INPUT_ERR));
	rgb = rgb_atoi(split[1]);
	if (rgb < 0)
		return (ft_error(COLOR_INPUT_ERR));
	new_color = ft_new_colorlst(split[0], rgb);
	if (!new_color)
		return (ft_error(COLOR_INITIAL_ERR));
	ft_colorlstadd_back(&(mlx->g->color_lst), new_color);
	return (false);
}
