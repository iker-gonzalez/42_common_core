/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:41:39 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/07/15 17:47:03 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*fill_str(long num, char *tmp, int j)
{
	if (!num)
	{
		tmp[0] = '0';
		return (tmp);
	}
	while (num > 0 )
	{
		tmp[--j] = (num % 10) + '0';
		num /= 10;
	}
	return (tmp);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	long	num;
	char	*tmp;

	num = (long)n;
	i = 0;
	j = ft_count(num);
	tmp = malloc (sizeof(char) * j + 1);
	if (tmp == NULL)
		return (NULL);
	if (num < 0)
	{
		tmp[0] = '-';
		num = -num;
	}
	tmp[j] = '\0';
	return (fill_str(num, tmp, j));
}
