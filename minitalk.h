/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokono <myokono@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:38:10 by myokono           #+#    #+#             */
/*   Updated: 2024/02/02 11:25:51 by myokono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_send_bit(int pid, char c);

void	ft_signal_handler(int sig, siginfo_t *info, void *context);

int		ft_atoi(const char *str);

int		ft_isdigit(int c);

void	ft_itoa_write(int n);

void	ft_signal_handler_client(int sig);

#endif
