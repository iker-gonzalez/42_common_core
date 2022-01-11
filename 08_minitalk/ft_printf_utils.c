/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:27:05 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/27 12:44:35 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_count_nb(int nb)
{
	int	size_nb;

	size_nb = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		size_nb++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		size_nb++;
	}
	return (size_nb);
}

int	ft_put_nb(int nb)
{
	int	count;

	count = ft_count_nb(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
		ft_put_nb(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
	return (count);
}
