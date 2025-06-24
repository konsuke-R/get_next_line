/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:40:45 by user              #+#    #+#             */
/*   Updated: 2025/06/23 22:29:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "get_next_line.h"

#define BUFFER_SIZE 1024

char *get_next_line(int fd) {
    char *buf;
    static char *save_line;
    int read_size;
    int pos_n;

    if (buf == NULL) {
        return NULL;
    }

    read_size = read(fd, buf, read_size);
    if (read_size < 0) {
        return NULL;
    }

    buf = ft_strjoin(save_line, buf);

    // \nを探してsplit
    // 前半をbufに保存してreturn, 後半をsaveに

    
}

char *til_n_str(*buf) {
    int i;
    char *cp_buf;
    i = 0;
    while (buf[i] && buf[i] != '\n') {
        cp_buf[i] = buf[i];
        i++;
    }

    if (buf[i] && buf[i] == '\n') {
        cp_buf[i] = buf[i];
        i++;
    }

    if (cp_buf == NULL) {
        return NULL;
    }

    cp_buf[i] = '\0';
    return cp_buf;
}

char *after_n_str(*buf) {
    int i;
    int j;
    char *cp_save_buf;
    i = 0;
    j = 0;
    while (buf[i] != '\n') {
        i++;
    }

    if (i == 0) {
        return NULL;
    }

    i++;

    while (buf[i]) {
        cp_buf[j++] = buf[i++]
    }

    cp_buf[j] = '\0';

    return cp_buf;
}