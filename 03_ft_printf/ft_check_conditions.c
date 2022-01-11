/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:41:27 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/09/28 18:27:38 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (c == 'u')
		counter = ft_put_unsigned_nb(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		counter = ft_put_hexadecimal(va_arg(args, unsigned int), c);
	if (c == 'p')
		counter = ft_put_pointer(va_arg(args, uintptr_t));
	return (counter);
}
