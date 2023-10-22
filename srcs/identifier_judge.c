/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_judge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:52:26 by wchen             #+#    #+#             */
/*   Updated: 2023/10/15 21:55:17 by wchen            ###   ########.fr       */
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

bool check_identifier(t_g_board *g_board, char *line)
{
	char **split_result;
	split_result = ft_split(line, ' ');
	if (incorrect_identify(split_result[0], IDENTIFIER))
		return (ft_error(IDENTIFIER_TYPE_ERR));
	return (add_id_lst(g_board,split_result));
}

bool identifier_judge(t_g_board *g_board, char *line)
{
	if (check_identifier(g_board, line))
		return (true);
	g_board->t_count ++;
	return (false);
}
