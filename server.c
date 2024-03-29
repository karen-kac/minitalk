/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokono <myokono@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:57:06 by myokono           #+#    #+#             */
/*   Updated: 2024/02/14 14:34:41 by myokono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\n", 1);
//			kill(info->si_pid, SIGUSR2);
		}
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	write(1, "Server PID:", 11);
	ft_itoa_write(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = ft_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
