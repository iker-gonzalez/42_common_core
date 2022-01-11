/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:37:06 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/01 12:57:40 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_signal_handler2(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Signal received!\n");
}

void	ft_char_binary(char c, int pid)
{
	int	i;
	int	ref;

	i = 0;
	ref = 128;
	while (ref > 0 && i <= 8)
	{
		usleep(50);
		if (c & ref)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		ref >>= 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Error\n");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	usleep(50);
	signal(SIGUSR1, ft_signal_handler2);
	i = 0;
	while (message[i])
	{
		ft_char_binary(message[i], pid);
		i++;
	}
}
