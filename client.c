/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:37:28 by afakili           #+#    #+#             */
/*   Updated: 2022/06/25 13:37:28 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(int p_id, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(p_id, SIGUSR1);
			else
				kill(p_id, SIGUSR2);
			usleep(50);
		}
	}
	i = 8;
	while (i--)
	{
		kill(p_id, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Hatalı / Eksik Giriş !");
		return (0);
	}
	ft_kill(ft_atoi(argv[1]), argv[2]);
}
