/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:52:05 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/13 10:49:07 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_result(int k, const char *str, int i)
{
	int	a;

	a = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = (a * 10) + (str[i] - '0');
		i++;
	}
	if (k == 1)
		a = a * -1;
	return (a);
}

intptr_t	ft_atoi(const char *str)
{
	intptr_t	a;
	int			i;
	int			k;

	a = 0;
	i = 0;
	k = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			k++;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		return (ft_result(k, str, i));
	return (a);
}
