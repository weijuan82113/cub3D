/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:06:25 by wchen             #+#    #+#             */
/*   Updated: 2023/11/12 21:56:02 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	extension_check(char *file_name)
{
	char	*ext;
	char	*ber;

	ber = ".cub";
	ext = ft_strrchr(file_name, '.');
	if (ext == NULL)
		return (true);
	if (ft_strncmp(ext, ber, 5) != 0)
		return (true);
	return (false);
}

static bool	file_check(t_mlx *mlx, char *file_path)
{
	int		fd;
	bool	check;

	errno = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_error(OPEN_FILE_ERR));
	check = fd_check(mlx, fd);
	close(fd);
	if (check)
		return (true);
	return (false);
}

bool	validation(t_mlx *mlx, int argc, char **argv)
{
	errno = 0;
	if (argc != 2)
		return (ft_error(ARG_ERR));
	if (extension_check(argv[1]))
		return (ft_error(FILE_EXT_ERR));
	if (file_check(mlx, argv[1]))
		return (true);
	return (false);
}
