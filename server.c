/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:27 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/14 18:12:16 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	str_create(void)
{
	g_info.str = malloc(sizeof(char) * g_info.len + 1);
	if (!g_info.str)
	{
		g_info.i = 0;
		return ;
	}
	g_info.str[g_info.len] = '\0';
	g_info.i = 0;
}

void	prints(siginfo_t *info)
{
	if (g_info.str[0] == '\0')
		kill(info->si_pid, SIGUSR1);
	ft_printf("%s\n", g_info.str);
	free(g_info.str);
	g_info.c = 0;
	g_info.i = 0;
	g_info.j = 0;
	g_info.len = 0;
	g_info.str = NULL;
}

void	prints_kill(siginfo_t *info)
{
	prints(info);
	kill(info->si_pid, SIGUSR1);
}

void	handler(int signal, siginfo_t *info, void *thingy)
{	
	(void)thingy;
	if (!g_info.str)
	{
		g_info.len = (g_info.len << 1) | (signal == SIGUSR1);
		if (++g_info.i == 31)
		{
			str_create();
			if (g_info.len == 0)
				prints(info);
		}	
	}
	else
	{	
		g_info.c = (g_info.c << 1) | (signal == SIGUSR1);
		if (++g_info.i == 8)
		{
			g_info.str[g_info.j] = g_info.c;
			g_info.j++;
			g_info.i = 0;
			g_info.c = 0;
			if (--g_info.len == 0)
				prints_kill(info);
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	g_info.c = 0;
	g_info.i = 0;
	g_info.j = 0;
	g_info.len = 0;
	g_info.str = NULL;
	ft_printf("pid: %d\n", pid);
	ft_printf("Waiting...\n");
	sig.sa_sigaction = handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
