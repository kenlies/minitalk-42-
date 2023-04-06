/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:27 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/06 14:45:21 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "ft_printf/include/libft.h"
#include "minitalk.h"

void	send(char c, pid_t pid)
{
	int	i;

	i = 0b10000000;
	while (i)
	{
		if (c & i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("ERROR!");
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("ERROR!");
				exit(0);
			}
		}
		i >>= 1;
		usleep(100);
	}
}

void	send_len(int len, pid_t pid)
{
	int	i;

	i = 0b1000000000000000000000000000000;
	while (i)
	{
		if (len & i)
		{
			if (kill(pid, SIGUSR1))
			{
				ft_printf("ERROR!");
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2))
			{
				ft_printf("ERROR!");
				exit(0);
			}
		}
		i >>= 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	send_len(ft_strlen(argv[2]), pid);
	while (message[i])
		send(message[i++], pid);
	return (0);
}
