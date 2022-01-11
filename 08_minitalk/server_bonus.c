/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:11:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/01 12:57:42 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_bin_to_dec(char *str)
{
	int	i;
	int	result;
	int	aux;

	i = 8;
	aux = 1;
	result = 0;
	while (i-- >= 0)
	{
		if (str[i] == '1')
			result += 1 * aux;
		aux *= 2;
	}
	return (result);
}

void	ft_signal_handler(int signum, siginfo_t *info, void *context )
{
	static int	count;
	static char	result[8];
	char		c;

	context = NULL;
	if (signum == SIGUSR1)
	{
		result[count] = '1';
		usleep(50);
	}
	else
	{
		result[count] = '0';
		usleep(50);
	}
	count++;
	if (count == 8)
	{
		c = ft_bin_to_dec(result);
		ft_printf("%c", c);
		count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	val;

	val.sa_mask = 0;
	val.sa_flags = 0;
	val.sa_sigaction = ft_signal_handler;
	pid = getpid();
	ft_printf("Proceso nº %d\n", pid);
	sigaction(SIGUSR1, &val, NULL);
	sigaction(SIGUSR2, &val, NULL);
	while (1)
		pause();
	return (1);
}
