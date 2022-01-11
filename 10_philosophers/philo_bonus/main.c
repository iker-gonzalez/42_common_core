/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:57:39 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/11 11:18:24 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

int	ft_odd_pair(t_ph *ph)
{
	static int	i;

	while (i++ < ph->th->nbr_philos)
		usleep(50);
	gettimeofday(&ph->t_born, NULL);
	if (ph->id % 2 == 0)
		ft_usleep(ph, 50);
	return (1);
}

void	ft_caseof1(t_ph *ph)
{
	gettimeofday(&ph->t_born, NULL);
	ft_usleep(ph, ph->th->t_die);
	printf("%d %d died\n", get_time_diff(ph->t_born), ph->id);
}

void	*routine(void *arg)
{
	t_ph		ph;

	ph = *(t_ph *)arg;
	if (ph.th->nbr_philos == 1)
	{
		ft_caseof1(&ph);
		return (NULL);
	}
	else
		ft_odd_pair(&ph);
	while (ph.meals)
	{
		if (ft_die(&ph))
			break ;
		ft_check_forks(&ph);
		ft_print_status(&ph, 's');
		if (ft_die(&ph))
			break ;
		ft_usleep(&ph, ph.th->t_sleep);
		ft_print_status(&ph, 't');
		if (ft_die(&ph))
			break ;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_th	th;
	t_ph	ph;
	int		i;
	int		*pid;
	int		*status;

	if (argc != 5 && argc != 6)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_structs_forks(&th, &ph, argc, argv);
	pid = malloc((sizeof (int)) * th.nbr_philos);
	i = -1;
	while (++i < th.nbr_philos)
	{	
		pid[i] = fork();
		if (pid == 0)
			routine(&ph);
	}
	i = -1;
	status = NULL;
	while (++i < th.nbr_philos)
		waitpid(-1, status, 0);
	//ft_destroy_mutex(&th);
}
