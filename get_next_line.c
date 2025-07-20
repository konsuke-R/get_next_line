/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkono <kkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:40:45 by user              #+#    #+#             */
/*   Updated: 2025/07/20 22:27:48 by kkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test用
#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*save_line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save_line = read_line(fd, save_line);
	if (!save_line)
		return (NULL);
	buf = get_before_n(save_line);
	tmp = save_line;
	save_line = get_after_n(save_line);
	free(tmp);
	if (!save_line || save_line[0] == '\0')
	{
		free(save_line);
		save_line = NULL;
	}
	return (buf);
}

char	*read_loop(int fd, char *save_line, char *buf)
{
	int		read_byte;
	char	*tmp;

	read_byte = 1;
	if (!save_line)
		save_line = ft_strdup("");
	while (!ft_strchr(save_line, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte < 0)
			return (NULL);
		buf[read_byte] = '\0';
		tmp = save_line;
		save_line = ft_strjoin(save_line, buf);
		free(tmp);
		if (!save_line)
			return (NULL);
	}
	return (save_line);
}

char	*read_line(int fd, char *save_line)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	save_line = read_loop(fd, save_line, buf);
	free(buf);
	return (save_line);
}

char	*get_before_n(const char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save || save[0] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, save, i + 1);
	line[i] = '\0';
	return (line);
}

char	*get_after_n(const char *save)
{
	int		i;
	char	*rem;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (NULL);
	rem = ft_strdup(save + i + 1);
	if (!rem)
		return (NULL);
	return (rem);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		line_num = 1;

// 	fd = open("test1.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("File open failed");
// 		return (1);
// 	}

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("line %d: %s", line_num++, line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
