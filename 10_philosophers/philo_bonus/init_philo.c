/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:57:14 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/11 11:15:24 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_th(t_th *th, char **argv)
{
	th->nbr_philos = ft_atoi(argv[1]);
	th->t_die = ft_atoi(argv[2]);
	th->t_eat = ft_atoi(argv[3]);
	th->t_sleep = ft_atoi(argv[4]);
	th->died = 0;
	sem_init(&th->s_eat, 1, th->nbr_philos);
	sem_init(&th->s_dead, 1, 1);
}

void	init_ph(t_ph *ph, t_th *th, int argc, char **argv)
{
	ph->id = 0;
	ph->th = th;
	ph->stamina = th->t_die;
	ph->t_last_meal = 0;
	if (argc == 6)
		ph->meals = ft_atoi(argv[5]);
	else
		ph->meals = -1;
}

void	init_structs_forks(t_th *th, t_ph *ph, int argc, char **argv)
{
	init_th(th, argv);
	init_ph(ph, th, argc, argv);
}
