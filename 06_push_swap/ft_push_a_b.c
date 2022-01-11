/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caseof100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:09:35 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 20:29:19 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_push_b(t_list **head_a, t_list **head_b, int part, int x)
{
	t_list	*tmp;

	tmp = *head_a;
	ft_pos_upd(head_a);
	while (tmp)
	{
		if (tmp->part == part && tmp-> mark == 1)
		{
			while (tmp->pos != 0)
			{
				ft_reverse_a(head_a);
				ft_pos_upd(head_a);
			}
			ft_push_b(head_b, head_a);
			ft_push_a_b(head_a, head_b, part, x);
		}
			tmp = tmp->next;
	}
}

void	ft_ra_push_b(t_list **head_a, t_list **head_b, int part, int x)
{
	t_list	*tmp;

	tmp = *head_a;
	ft_pos_upd(head_a);
	while (tmp)
	{
		if (tmp->part == part)
		{
			while (tmp->pos != 0)
			{
				ft_rotate_a(head_a);
				ft_pos_upd(head_a);
			}
			ft_push_b(head_b, head_a);
			ft_push_a_b(head_a, head_b, part, x);
		}		
		tmp = tmp->next;
	}
}

void	ft_push_a_b(t_list **head_a, t_list **head_b, int part, int x)
{	
	while (part <= x)
	{
		if (ft_ra_rra_mov(head_a, part) == 1)
			ft_ra_push_b(head_a, head_b, part, x);
		else if (ft_ra_rra_mov(head_a, part) == 0)
			ft_rra_push_b(head_a, head_b, part, x);
		else
			ft_push_a_b(head_a, head_b, ++part, x);
	}
}
