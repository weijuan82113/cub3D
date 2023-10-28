/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_judge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:52:26 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 17:25:32 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool incorrect_identify(char* s, char* compare)
{
	int i;
	char **identifier_array;
	int	identifier_num;

	identifier_array = ft_split(compare, '/');
	identifier_num = 0;
	while (identifier_array[identifier_num])
		identifier_num++;
	i = 0;
	while(i < identifier_num)
	{
		if (ft_strncmp(s, identifier_array[i], ft_strlen(identifier_array[i])) == 0)
			return (false);
		i ++;
	}
	return(true);
}

bool check_identifier(t_mlx *mlx, char *line)
{
	char **line_split;

	line_split = ft_split(line, ' ');
	if (incorrect_identify(line_split[0], IDENTIFIER))
		return (ft_error(IDENTIFIER_TYPE_ERR));
	//separete color and img
	if (ft_strlen(line_split[0]) == 2)
		return (add_img_lst(mlx, line_split));
	else
		return (add_color_lst(mlx, line_split));
}

bool identifier_judge(t_mlx *mlx, char *line)
{
	if (check_identifier(mlx, line))
		return (true);
	mlx->g->t_count ++;
	return (false);
}
