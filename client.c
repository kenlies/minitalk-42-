/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:27 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/14 18:25:59 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(char c, int pid)
{
	int	i;

	i = 0b10000000;
	while (i)
	{
		if (c & i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "ERROR\n", 6);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "ERROR\n", 6);
				exit(1);
			}
		}
		i >>= 1;
		usleep(100);
	}
}

void	send_len(int len, int pid)
{
	int	i;

	i = 0b1000000000000000000000000000000;
	while (i)
	{
		if (len & i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "ERROR\n", 6);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "ERROR\n", 6);
				exit(1);
			}
		}
		i >>= 1;
		usleep(100);
	}
}

static void	ack(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Acknowledged by server!\n");
	}
	else
		write(2, "Something went wrong!\n", 22);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, &ack);
	signal(SIGUSR2, &ack);
	send_len(ft_strlen(argv[2]), pid);
	while (message[i])
		send(message[i++], pid);
	while (1)
		pause();
	return (0);
}
