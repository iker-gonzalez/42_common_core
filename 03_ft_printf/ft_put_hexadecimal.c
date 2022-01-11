/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:37:16 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/09/28 18:30:54 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexadecimal(uintptr_t nb, char c)
{
	static int	count;

	count = 0;
	if (nb >= 16)
	{
		ft_put_hexadecimal(nb / 16, c);
		nb = nb % 16;
	}
	if (nb < 16)
	{
		if (nb <= 9)
		{
			ft_putchar (nb + '0');
			count++;
		}
		else
		{
			if (c == 'x')
				ft_putchar(nb + 87);
			else
				ft_putchar(nb + 55);
			count++;
		}
	}
	return (count);
}
