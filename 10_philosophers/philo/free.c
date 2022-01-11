/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:17:24 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/10 14:03:34 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_destroy_mutex(t_th *th)
{
	int	i;

	pthread_mutex_destroy(&th->init_mutex);
	pthread_mutex_destroy(&th->dead_mutex);
	i = 0;
	while (i < th->nbr_philos)
	{
		pthread_mutex_destroy(&th->eat_mutex[i]);
		i++;
	}
	free(th->eat_mutex);
	free(th->th);
	return (0);
}
