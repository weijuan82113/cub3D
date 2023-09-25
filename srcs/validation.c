/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:06:25 by wchen             #+#    #+#             */
/*   Updated: 2023/09/25 23:27:27 by wchen            ###   ########.fr       */
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

bool file_check(int fd)
{
	char *line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s",line);
	}
	return (false);
}

bool map_check(char *file_path)
{
	int fd;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror(OPEN_FILE_ERR);
		return (true);
	}
	if (file_check(fd))
		return (true);
	return (false);

}

bool validation(int argc, char**argv)
{
	(void) argv;
	if (argc != 2)
		return (ft_error(ARG_ERR));
	if (extension_check(argv[1]))
		return (ft_error(FILE_EXT_ERR));
	if (map_check(argv[1]))
		return (true);
	return (false);
}
