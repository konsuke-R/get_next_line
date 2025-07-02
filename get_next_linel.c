/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:40:45 by user              #+#    #+#             */
/*   Updated: 2025/06/30 23:50:37 by user             ###   ########.fr       */
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

    buf = til_n_str(save_line);
    save_line = after_n_str(save_line);
    if (save_line == NULL) {
        read_byte = read(fd, save_line, BUFFER_SIZE);
    }

    if (read_byte <= 0) {
        return NULL;
    }

    return buf;
}

char *til_n_str(char *buf) {
    int i;
    i = 0;

    if (!buf)
        return NULL;
    // 改行文字以外をコピー
    while (buf[i] && buf[i] != '\n'){
        i++;
    }

    // 改行文字をコピー
    // ex)abcde\n
    if (buf[i] && buf[i] == '\n') {
        i++;
    }

    char *cp_buf = (char*)malloc(i + 1);
    if (!cp_buf)
        return NULL;

    for (int j = 0; j < i; j++) {
        cp_buf[j] = buf[j];
    }
    // 終端文字を追加
    cp_buf[i] = '\0';

    // コピーした変数をリターン
    return cp_buf;
}

char *after_n_str(char *buf) {
    if (!buf)
        return NULL;
    int i;
    i = 0;

    // 添え字iを改行文字まで移動
    while (buf[i] && buf[i] != '\n') {
        i++;
    }

    if (buf[i] == '\0')
        return NULL;
    // 改行文字の次へ
    i++;

    // 改行文字以降をコピー
    while (buf[i]) {
        cp_buf[j++] = buf[i++];
    }

    // 終端文字を追加
    cp_buf[j] = '\0';

    return cp_buf;
}