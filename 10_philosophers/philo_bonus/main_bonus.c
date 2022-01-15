/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:57:39 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/13 11:44:44 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
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
	sem_post(ph.th->init);
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

void	ft_create_process(t_ph *ph)
{
	int	i;

	i = -1;
	while (++i < ph->th->nbr_philos)
	{	
		ph->th->pid[i] = fork();
		ph->id = i + 1;
		if (ph->th->pid[i] == 0)
			routine(ph);
	}
}

int	main(int argc, char **argv)
{
	t_th	th;
	t_ph	ph;
	int		i;
	int		status;

	if (argc != 5 && argc != 6)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_structs(&th, &ph, argc, argv);
	sem_wait(th.init);
	ft_create_process(&ph);
	i = -1;
	while (++i < th.nbr_philos)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
			ft_kill_them_all(&ph);
	}
	ft_destroy_sem(&th);
	return (0);
}
