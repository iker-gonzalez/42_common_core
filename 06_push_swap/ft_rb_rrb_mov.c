/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:23:48 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 20:18:12 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rrb_mov(t_list **head, int biggest)
{
	int		mov;
	int		i;
	t_list	*tmp;

	ft_reverse_list(head);
	tmp = *head;
	mov = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->content == biggest)
		{
			tmp->mark = 2;
			ft_reverse_list(head);
			return (mov + 1);
		}
		tmp = tmp->next;
		mov++;
	}
	ft_reverse_list(head);
	return (5000);
}

int	ft_rb_mov(t_list **head, int biggest)
{
	int		mov;
	t_list	*tmp;

	tmp = *head;
	mov = 0;
	while (tmp)
	{
		if (tmp->content == biggest)
			return (mov);
		tmp = tmp->next;
		mov++;
	}
	return (5000);
}

int	ft_rb_rrb_mov(t_list **lst, int biggest)
{
	int	rb_mov;
	int	rrb_mov;

	rb_mov = ft_rb_mov(lst, biggest);
	rrb_mov = ft_rrb_mov(lst, biggest);
	if (rb_mov + rrb_mov == 10000)
		return (2);
	if (rb_mov <= rrb_mov)
		return (1);
	else
		return (0);
}
