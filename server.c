/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:27 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/06 14:44:06 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/include/ft_printf.h"
#include "ft_printf/include/libft.h"

t_info	g_info;

void	setzero(void)
{
	g_info.c = 0;
	g_info.i = 0;
	g_info.j = 0;
	g_info.len = 0;
	g_info.str = NULL;
}

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

void	prints(void)
{
	ft_printf("%s\n", g_info.str);
	free(g_info.str);
	setzero();
}

void	handler(int signal)
{
	if (!g_info.str)
	{
		g_info.len = (g_info.len << 1) | (signal == SIGUSR1);
		if (++g_info.i == 31)
		{
			str_create();
			if (g_info.len == 0)
				prints();
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
				prints();
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	setzero();
	ft_printf("pid: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
