/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_judge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:52:26 by wchen             #+#    #+#             */
/*   Updated: 2024/03/19 23:54:14 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	incorrect_identify(char *s, char **id_split)
{
	int	i;

	i = 0;
	while (i < IDENTIFIER_NUM)
	{
		if (id_split[i] && ft_strncmp(s, id_split[i],
				ft_strlen(id_split[i]) + 1) == 0)
		{
			free (id_split[i]);
			id_split[i] = NULL;
			return (false);
		}
		i++;
	}
	return (true);
}

static int	split_num(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i ++;
	return (i);
}

static char	**generate_line_split(const char *line)
{
	char	*tmp;
	char	**ret;

	tmp = ft_strtrim(line, " \r\n");
	if (tmp == NULL)
		return (NULL);
	ret = ft_split(tmp, ' ');
	free(tmp);
	return (ret);
}

static bool	check_identifier(t_mlx *mlx, char *line)
{
	char	**line_split;
	bool	result;

	errno = 0;
	line_split = generate_line_split(line);
	if (line_split == NULL)
		return (ft_error(MALLOC_ERR));
	if (split_num(line_split) != 2)
	{
		free_split(line_split);
		return (ft_error(IDENTIFIER_PATH_ERR));
	}
	result = false;
	if (incorrect_identify(line_split[0], mlx->g->identifier))
	{
		free_split(line_split);
		return (ft_error(IDENTIFIER_TYPE_ERR));
	}
	if (ft_strlen(line_split[0]) == 2)
		result = add_img_lst(mlx, line_split);
	else
		result = add_color_lst(mlx, line_split);
	free_split(line_split);
	return (result);
}

bool	identifier_judge(t_mlx *mlx, char *line)
{
	if (check_identifier(mlx, line))
		return (true);
	mlx->g->t_count++;
	return (false);
}
