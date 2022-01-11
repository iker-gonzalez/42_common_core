/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:58:57 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/11 11:16:21 by ikgonzal         ###   ########.fr       */
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
	sem_wait(&ph->th->s_eat);
	ft_die(ph);
	ft_print_status(ph, 'f');
	ft_die(ph);
	sem_wait(&ph->th->s_eat);
	ft_die(ph);
	ft_print_status(ph, 'f');
	ft_eat(ph);
	sem_post(&ph->th->s_eat);
	sem_post(&ph->th->s_eat);
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
	sem_wait(&ph->th->s_dead);
	if (ph->stamina < get_time_diff(ph->t_born) - ph->t_last_meal
		&& !ph->th->died)
	{
		ft_print_status(ph, 'd');
		ph->th->died = 1;
	}
	sem_post(&ph->th->s_dead);
	return (0);
}
