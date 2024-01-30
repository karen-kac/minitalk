/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokono <myokono@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:56:58 by myokono           #+#    #+#             */
/*   Updated: 2024/01/30 17:57:16 by myokono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void ft_send_bit(int pid, char c)
{
	int	i;

	i = 0;
    while (i < 8)
    {
        usleep(100);
        if (c & (1 << i))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
		i++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    char *message;

    if (argc != 3)
    {
        ft_printf("Usage: %s [server_pid] [message]\n", argv[0]);
        return 1;
    }

    pid = ft_atoi(argv[1]);
    message = argv[2];

    while (*message)
    {
        ft_send_bit(pid, *message);
        message++;
    }

    return 0;
}