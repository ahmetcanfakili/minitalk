/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:19:35 by afakili           #+#    #+#             */
/*   Updated: 2022/06/25 13:19:35 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig_no, siginfo_t *info, void *content)
{
	static char		character = 0;
	static pid_t	client_id = 0;
	static int		get_bit = 0;

	(void)content;
	if (client_id == 0)
		client_id = info->si_pid;
	if (sig_no == SIGUSR1)
		character |= 1;
	if (++get_bit == 8)
	{
		get_bit = 0;
		if (!character)
		{
			kill(client_id, SIGUSR1);
			client_id = 0;
			ft_printf("\n");
		}
		ft_printf("%c", character);
		character = 0;
	}
	else
		character <<= 1;
}

int	main(void)
{
	struct sigaction	client;

	client.sa_flags = SA_SIGINFO;
	client.sa_sigaction = sig_handler;
	ft_printf("Server ID: %d\n", getpid());
	sigaction(SIGUSR1, &client, 0);
	sigaction(SIGUSR2, &client, 0);
	while (1)
		pause();
	return (0);
}
