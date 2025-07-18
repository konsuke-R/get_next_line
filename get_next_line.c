/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:40:45 by user              #+#    #+#             */
/*   Updated: 2025/07/18 20:57:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// test用
#include <fcntl.h>

#include "get_next_line.h"
char *get_next_line(int fd) {
    char *buf;
    static char *save_line;
    char *tmp;
    int read_byte;

    read_byte = 0;

    if (!save_line)
        save_line = ft_strdup("");

    if (fd < 0|| BUFFER_SIZE <= 0) {
        return (0);
    }

    // saveに/nを含めるまで文字列を読みこみ
    save_line = read_line(fd, save_line);
    if (!save_line)
        return (NULL);

    // lineに改行より前に来る文字列を
    buf = get_before_n(save_line);
    tmp = save_line;

    // saveに改行より後にくる文字列を
    save_line = get_after_n(save_line);
    free(tmp);

    // lineを出力
    return (buf);
}

char *read_line(int fd, char* save_line)
{
    char *buf;
    char *tmp;
    int read_byte;

    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);

    read_byte = 1;
    
    while (save_line && !ft_strchr(save_line, '\n') && read_byte > 0)
    {
        read_byte = read(fd, buf, BUFFER_SIZE);
        if (read_byte < 0)
        {
            free(buf);
            return (NULL);
        }
        buf[read_byte] = '\0';
        tmp = save_line;
        save_line = ft_strjoin(save_line, buf);
        free(tmp);
        if (!save_line)
        {
            free(buf);
            return (NULL);
        }
    }
    free(buf);
    return (save_line);
}

char *get_before_n(const char *save)
{
    int i;
    char *line;
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

    return line;
}

char *get_after_n(const char*save)
{
    int i;
    char *rem;
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

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}