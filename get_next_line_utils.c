/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:52:04 by user              #+#    #+#             */
/*   Updated: 2025/07/18 20:31:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		str_len;
	int		cnt1;
	int		cnt2;

	str_len = all_strlen(s1, s2);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	cnt1 = 0;
	cnt2 = 0;
	while (s1[cnt1])
	{
		str[cnt1] = s1[cnt1];
		cnt1++;
	}
	while (s2[cnt2])
	{
		str[cnt1 + cnt2] = s2[cnt2];
		cnt2++;
	}
	str[cnt1 + cnt2] = '\0';
	return (str);
}

int	all_strlen(char const *s1, char const *s2)
{
	int	s1_len;
	int	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return (s1_len + s2_len);
}

size_t	ft_strlcpy(char *dest, const char *restrict src, size_t dsize)
{
	size_t	i;
	size_t	size_s;

	size_s = ft_strlen(src);
	i = 0;
	if (dsize == 0)
		return (size_s);
	if (size_s < dsize)
	{
		while (i < size_s)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < dsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (size_s);
}

char	*ft_strdup(const char *s)
{
	char	*sd;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	i = 0;
	sd = (char *)malloc(sizeof(char) * (len + 1));
	if (!sd)
		return (NULL);
	while (i < len)
	{
		sd[i] = s[i];
		i++;
	}
	sd[i] = '\0';
	return (sd);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}