/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:12:54 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/24 10:17:50 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_pair(int nb)
{
	if (nb % 5 != 0)
		nb = nb + (5 - nb % 5);
	return (nb);
}

int	ft_part(t_list **lst, int range_min, int range_max, int part)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->rank >= range_min && tmp->rank < range_max)
			tmp->part = part;
			tmp = tmp->next;
	}
	return (1);
}

void	ft_iterate_part(t_list **head_a, t_list **head_b, int size, int x)
{
	int	part;
	int	i;
	int	range_min;
	int	range_max;
	int	size_part;

	*head_b = NULL;
	size_part = ft_check_pair(size) / x + 1;
	range_min = 0;
	range_max = size_part;
	part = 0;
	i = 0;
	while (part <= x)
	{
		i += ft_part(head_a, range_min, range_max, part++);
		range_min = range_max;
		range_max = range_max + size_part;
	}
}
