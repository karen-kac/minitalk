/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokono <myokono@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:38:10 by myokono           #+#    #+#             */
/*   Updated: 2024/01/30 17:53:27 by myokono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "libftprintf/ft_printf.h"


// ここに必要に応じて追加のマクロ定義や関数のプロトタイプを定義します。

// クライアントが使用する関数のプロトタイプ
void ft_send_bit(int pid, char c);

// サーバーが使用する関数のプロトタイプ
void ft_signal_handler(int sig, siginfo_t *info, void *context);

#endif

