/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:36:59 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/13 11:44:29 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo_bonus.h"

int	get_time_diff(struct timeval ta)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000 + tm.tv_usec / 1000)
		- (ta.tv_sec * 1000 + ta.tv_usec / 1000));
}

void	ft_usleep(t_ph *ph, int time)
{
	struct timeval	before;
	struct timeval	end;

	gettimeofday(&before, NULL);
	gettimeofday(&end, NULL);
	while (((end.tv_sec * 1000 + end.tv_usec / 1000)
			- (before.tv_sec * 1000 + before.tv_usec / 1000)) < time)
	{
		ft_die(ph);
		usleep(100);
		ft_die(ph);
		gettimeofday(&end, NULL);
	}
}
