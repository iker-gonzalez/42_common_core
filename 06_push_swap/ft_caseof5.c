/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caseof5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:55:43 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 19:59:55 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_iterate_5(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	int		i;

	tmp = *head_a;
	i = 0;
	while (tmp != NULL)
	{
		tmp = *head_a;
		if (tmp->mark == 1 && i < 2)
		{
			ft_push_b(head_b, head_a);
			i++;
		}
		else
			ft_rotate_a(head_a);
		if (i == 2)
			break ;
		tmp = *head_a;
		tmp = tmp->next;
	}
}

void	ft_caseof5(t_list **head_a, t_list **head_b)
{
	ft_small(head_a);
	ft_iterate_5(head_a, head_b);
	ft_caseof3(head_a);
	if ((*head_b)->content < (*head_b)->next->content)
		ft_swap_b(head_b);
	ft_push_a(head_a, head_b);
	ft_push_a(head_a, head_b);
}
