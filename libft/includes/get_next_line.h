/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:15:08 by wchen             #+#    #+#             */
/*   Updated: 2024/02/08 21:28:52 by wchen            ###   ########.fr       */
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

size_t	ft_strlen_gnl(const char *c);
void	*ft_memchr_gnl(const void *s, int c, size_t n);
char	*ft_strjoin_and_free_s1(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *src);

#endif
