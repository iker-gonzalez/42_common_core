/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_of_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:38:37 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/24 11:16:30 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_distribution(t_list **head_a, t_list **head_b, int size)
{
	if (size == 2)
		ft_swap_a(head_a);
	if (size == 3)
		ft_caseof3(head_a);
	if (size == 4)
		ft_caseof4(head_a, head_b);
	if (size == 5)
		ft_caseof5(head_a, head_b);
	if (size > 5 && size <= 100)
	{
		ft_iterate_part(head_a, head_b, size, 4);
		ft_push_a_b(head_a, head_b, 0, 4);
		ft_push_b_a(head_a, head_b);
	}
	if (size > 100)
	{
		ft_iterate_part(head_a, head_b, size, 10);
		ft_push_a_b(head_a, head_b, 0, 10);
		ft_push_b_a(head_a, head_b);
	}
}
