/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:10:54 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/07/15 17:46:40 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_atoi(const char *str)
{
	int	a;
	int	i;
	int	k;

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
