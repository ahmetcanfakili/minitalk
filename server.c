/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:37:22 by afakili           #+#    #+#             */
/*   Updated: 2022/06/25 13:37:22 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal_no)
{
	static char	character = 0;
	static int	bit_count = 0;

	if (signal_no == SIGUSR1)
		character |= 1;
	if (++bit_count == 8)
	{
		bit_count = 0;
		if (!character)
			ft_printf("\n");
		ft_printf("%c", character);
		character = 0;
	}
	else
		character <<= 1;
}

int	main(void)
{
	ft_printf("Server ID: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
