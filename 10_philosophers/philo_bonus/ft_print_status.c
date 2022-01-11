/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:47:53 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/11 10:05:59 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_status_conversion(char c)
{
	char	*str;

	if (c == 'e')
		str = "is eating\n";
	else if (c == 'f')
		str = "has taken a fork\n";
	else if (c == 's')
		str = "is sleeping\n";
	else if (c == 't')
		str = "is thinking\n";
	else
		str = "died\n";
	return (str);
}

void	ft_print_status(t_ph *ph, char c)
{
	char	*str;

	str = ft_status_conversion(c);
	if (!ph->th->died && ph->meals != 0)
		printf("%d %d %s", get_time_diff(ph->t_born), ph->id, str);
}
