/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:03:53 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 20:17:59 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb_push_a(t_list **head_a, t_list **head_b, int biggest)
{
	t_list	*tmp;

	tmp = *head_b;
	ft_pos_upd(head_b);
	while (tmp)
	{
		if (tmp->content == biggest && tmp->mark == 2)
		{
			while (tmp->pos != 0)
			{
				ft_reverse_b(head_b);
				ft_pos_upd(head_b);
			}
			ft_push_a(head_a, head_b);
			ft_push_b_a(head_a, head_b);
		}
		tmp = tmp->next;
	}
}

void	ft_rb_push_a(t_list **head_a, t_list **head_b, int biggest)
{
	t_list	*tmp;

	tmp = *head_b;
	ft_pos_upd(head_b);
	while (tmp)
	{
		if (tmp->content == biggest)
		{
			while (tmp->pos != 0)
			{
				ft_rotate_b(head_b);
				ft_pos_upd(head_b);
			}
			ft_push_a(head_a, head_b);
			ft_push_b_a(head_a, head_b);
		}
		tmp = tmp->next;
	}
}

void	ft_push_b_a(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_b;
	while (*head_b)
	{
		if (ft_rb_rrb_mov(head_b, ft_biggest_content(tmp)) == 1)
			ft_rb_push_a(head_a, head_b, ft_biggest_content(tmp));
		else if (ft_rb_rrb_mov(head_b, ft_biggest_content(tmp)) == 0)
			ft_rrb_push_a(head_a, head_b, ft_biggest_content(tmp));
		else
			exit (0);
	}
}
