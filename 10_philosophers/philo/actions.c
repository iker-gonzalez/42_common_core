/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:58:57 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/13 10:48:50 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_forks(t_ph *ph)
{
	int	left_fork;

	left_fork = ph->id;
	if (ph->id == ph->th->nbr_philos)
		left_fork = 0;
	ft_die(ph);
	pthread_mutex_lock(&ph->th->eat_mutex[ph->id - 1]);
	ft_die(ph);
	ft_print_status(ph, 'f');
	ft_die(ph);
	pthread_mutex_lock(&ph->th->eat_mutex[left_fork]);
	ft_die(ph);
	ft_print_status(ph, 'f');
	ft_eat(ph);
	pthread_mutex_unlock(&ph->th->eat_mutex[ph->id - 1]);
	pthread_mutex_unlock(&ph->th->eat_mutex[left_fork]);
	ft_die(ph);
}

void	ft_eat(t_ph *ph)
{
	ft_print_status(ph, 'e');
	ft_usleep(ph, ph->th->t_eat);
	ph->t_last_meal = get_time_diff(ph->t_born);
	if (ph->meals > 0)
		ph->meals--;
}

int	ft_die(t_ph *ph)
{
	if (ph->th->died == 1 || ph->meals == 0)
		return (1);
	pthread_mutex_lock(&ph->th->dead_mutex);
	if (ph->stamina < get_time_diff(ph->t_born) - ph->t_last_meal
		&& !ph->th->died)
	{
		ft_print_status(ph, 'd');
		ph->th->died = 1;
	}
	pthread_mutex_unlock(&ph->th->dead_mutex);
	return (0);
}
