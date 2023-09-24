/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:06:25 by wchen             #+#    #+#             */
/*   Updated: 2023/09/24 22:29:52 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool extension_check(char *file_name)
{
	char	*ext;
	char	*ber;

	ber = ".cub";
	ext = ft_strrchr(file_name, '.');
	if (ext == NULL)
		return (true);
	while (*ext != '\0' && *ber != '\0')
	{
		if (*(ext) != *ber)
			return (true);
		ext++;
		ber++;
	}
	if (*ext != '\0' || *ber != '\0')
		return (true);
	return (false);
}

bool validation(int argc, char**argv)
{
	(void) argv;
	if (argc != 2)
		return (true);
	if (extension_check(argv[1]))
		return (true);
	return (false);
}
