/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:40:45 by user              #+#    #+#             */
/*   Updated: 2025/07/15 09:16:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "get_next_line.h"


char *get_next_line(int fd) {
    char *buf;
    static char *save_line;
    int read_byte;

    read_byte = 0;

    if (fd < 0|| BUFFER_SIZE <= 0) {
        return (0);
    }

    // saveに/nを含めた文字列を読みこみ
    save_line = read_line(fd, save_line);

    // lineに改行より前に来る文字列を

    // saveに改行より後にくる文字列を

    // lineを出力
}

char *read_line(int fd, char* save_line)
{
    
}
