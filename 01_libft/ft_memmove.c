/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:14:22 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/06/08 18:39:22 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	str_src = (unsigned char *)src;
	str_dst = (unsigned char *)dst;
	if (src != '\0' || dst != '\0')
	{
		if (dst > src)
		{	
			while (len-- > 0)
				str_dst[len] = str_src[len];
		}
		else
		{
			i = 0;
			while (i < len)
			{
				str_dst[i] = str_src[i];
				i++;
			}
		}
		return (dst);
	}
	return (NULL);
}
