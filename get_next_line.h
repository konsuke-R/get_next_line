/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:13:02 by user              #+#    #+#             */
/*   Updated: 2025/07/18 20:29:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFFER_SIZE 1024

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char *read_line(int fd, char* save_line);
char *get_before_n(const char *save);
char *get_after_n(const char*save);

char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int	all_strlen(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *restrict src, size_t dsize);
char	*ft_strdup(const char *s);
size_t ft_strlen(const char*s);


#endif