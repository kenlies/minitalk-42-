/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:27 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/13 19:38:24 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

typedef struct s_info
{
	int				i;
	int				j;
	int				len;
	unsigned char	c;
	char			*str;
}				t_info;

#endif