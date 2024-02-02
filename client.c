/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokono <myokono@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:56:58 by myokono           #+#    #+#             */
/*   Updated: 2024/02/02 12:12:37 by myokono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bit(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	ft_signal_handler_client(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Message successfully sent!\n", 27);
		exit(0);
	}
}

static int	get_valid_pid(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !ft_isdigit(*argv[1]))
	{
		write(1, "Usage: ./client [server_pid] [message]\n", 39);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
	{
		write(1, "Error: Invalid PID.\n", 20);
		return (-1);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	pid = get_valid_pid(argc, argv);
	if (pid == -1)
		return (1);
	signal(SIGUSR2, ft_signal_handler_client);
	message = argv[2];
	while (*message)
	{
		ft_send_bit(pid, *message);
		message++;
	}
	ft_send_bit(pid, '\0');
	pause();
	return (0);
}
