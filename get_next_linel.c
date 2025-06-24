/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:40:45 by user              #+#    #+#             */
/*   Updated: 2025/06/24 22:14:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "get_next_line.h"

char *get_next_line(int fd) {
    char *buf;
    static char *save_line;
    int read_size;
    int pos_n;

    buf = save_line;

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
    // 改行文字までコピー
    while (buf[i] && buf[i] != '\n') {
        cp_buf[i] = buf[i];
        i++;
    }

    // 最終行でなければ、改行文字をコピー
    // ex)abcde\n
    if (buf[i] && buf[i] == '\n') {
        cp_buf[i] = buf[i];
        i++;
    }

    // コピーするものがなかったらnull
    if (cp_buf == NULL) {
        return NULL;
    }

    // 終端文字を追加
    cp_buf[i] = '\0';

    // コピーした変数をリターン
    return cp_buf;
}

char *after_n_str(*buf) {
    int i;
    int j;
    char *cp_save_buf;
    i = 0;
    j = 0;

    // 添え字iを改行文字まで移動
    while (buf[i] != '\n') {
        i++;
    }

    if (i == 0) {
        return NULL;
    }

    // 改行文字の次へ
    i++;

    // 改行文字以降をコピー
    while (buf[i]) {
        cp_buf[j++] = buf[i++]
    }

    // 終端文字を追加
    cp_buf[j] = '\0';

    return cp_buf;
}