/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:52:38 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/30 15:08:06 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check_conditions(char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = ft_putchar(va_arg(args, int));
	if (c == 's')
		counter = ft_putstr(va_arg(args, char *));
	if (c == '%')
		counter = write(1, "%", 1);
	if (c == 'i' || c == 'd')
		counter = ft_put_nb(va_arg(args, int));
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		k;
	int		count;

	va_start(args, format);
	count = 0;
	i = 0;
	k = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_check_conditions(format[i + 1], args);
			i++;
			k++;
		}
		else
			write(1, &format[i], 1);
		count++;
		i++;
	}
	va_end(args);
	return (count - k);
}
