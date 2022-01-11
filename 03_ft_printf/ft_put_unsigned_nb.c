/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:49:47 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/09/28 18:35:37 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_unsigned_nb(unsigned int nb)
{
	int	size_unsigned_nb;

	size_unsigned_nb = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		size_unsigned_nb++;
	}
	return (size_unsigned_nb);
}

int	ft_put_unsigned_nb(unsigned int nb)
{
	int	count;

	if (nb == 0)
		count = 1;
	else
		count = ft_count_unsigned_nb(nb);
	if (nb > 9)
		ft_put_unsigned_nb(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
	return (count);
}
