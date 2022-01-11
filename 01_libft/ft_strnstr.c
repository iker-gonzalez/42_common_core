/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:47:11 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/07/14 16:52:23 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	u;

	i = 0;
	if (!find[0])
		return ((char *)str);
	while (str[i] && i < len)
	{
		u = 0;
		while (str[i + u] == find[u] && (i + u) < len)
		{
			if (find[u + 1] == 0)
				return ((char *)&str[i]);
			u++;
		}
		i++;
	}
	return (0);
}
