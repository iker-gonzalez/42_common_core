/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:37:06 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/01 12:15:57 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_char_binary(char c, int pid)
{
	int	i;
	int	ref;

	i = 0;
	ref = 128;
	while (ref > 0 && i <= 8)
	{
		if (c & ref)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
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
	i = 0;
	while (message[i])
	{
		ft_char_binary(message[i], pid);
		i++;
	}
}
