/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:17:24 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/13 11:44:13 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_destroy_sem(t_th *th)
{
	sem_close(th->init);
	sem_close(th->forks);
	sem_close(th->death);
	free(th->pid);
	return (0);
}
