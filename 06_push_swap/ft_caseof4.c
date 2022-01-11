/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caseof4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:11:15 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 19:59:30 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_caseof4(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_a;
	while (tmp)
	{
		if (tmp->rank == 0)
		{
			while (tmp->pos != 0)
			{
				ft_rotate_a(head_a);
				tmp->pos = tmp->pos - 1;
			}
			ft_push_b(head_b, head_a);
		}
		tmp = tmp->next;
	}
	ft_caseof3(head_a);
	ft_push_a(head_a, head_b);
}
