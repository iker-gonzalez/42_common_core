/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:57:14 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/13 12:39:57 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_th(t_th *th, char **argv)
{
	th->nbr_philos = ft_atoi(argv[1]);
	th->t_die = ft_atoi(argv[2]);
	th->t_eat = ft_atoi(argv[3]);
	th->t_sleep = ft_atoi(argv[4]);
	th->died = 0;
	th->pid = malloc((sizeof (pid_t)) * (th->nbr_philos));
	sem_unlink("init");
	th->init = sem_open("init", O_CREAT, 0644, 1);
	sem_unlink("forks");
	th->forks = sem_open("forks", O_CREAT, 0644, th->nbr_philos);
	sem_unlink("death");
	th->death = sem_open("death", O_CREAT, 0644, 1);
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

void	init_structs(t_th *th, t_ph *ph, int argc, char **argv)
{
	init_th(th, argv);
	init_ph(ph, th, argc, argv);
}
