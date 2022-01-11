/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:44:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/09/28 18:42:50 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_put_nb(int nb);
int	ft_count_nb(int nb);
int	ft_putstr(char *str);
int	ft_check_conditions(char c, va_list args);
int	ft_putchar(char c);
int	ft_put_unsigned_nb(unsigned int nb);
int	ft_count_unsigned_nb(unsigned int nb);
int	ft_put_hexadecimal(uintptr_t nb, char c);
int	ft_put_pointer(uintptr_t nb);

#endif
