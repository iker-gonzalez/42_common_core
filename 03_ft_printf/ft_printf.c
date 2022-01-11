/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:52:38 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/09/28 18:24:39 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
