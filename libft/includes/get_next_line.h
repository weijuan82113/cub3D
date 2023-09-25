/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:15:08 by wchen             #+#    #+#             */
/*   Updated: 2023/09/25 23:00:56 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifdef BUFFER_SIZE
# else
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *c);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
