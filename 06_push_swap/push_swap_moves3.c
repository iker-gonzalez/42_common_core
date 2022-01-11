/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:23:12 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 19:32:59 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_a(t_list **head_a)
{
	t_list	*tail;
	t_list	*tmp;

	if (!*head_a)
		return ;
	tail = *head_a;
	tmp = *head_a;
	tail = ft_lstlast(tail);
	ft_lstadd_front(head_a, tail);
	while (tmp ->next != tail)
		tmp = tmp->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_reverse_b(t_list **head_b)
{
	t_list	*tail;
	t_list	*tmp;

	if (!*head_b)
		return ;
	tail = *head_b;
	tmp = *head_b;
	tail = ft_lstlast(tail);
	ft_lstadd_front(head_b, tail);
	while (tmp ->next != tail)
		tmp = tmp->next;
	tmp->next = NULL;
	write (1, "rrb\n", 4);
}

void	ft_reverse_a_b(t_list **head_a, t_list **head_b)
{
	if (!head_a || head_b)
		return ;
	ft_reverse_a(head_a);
	ft_reverse_b(head_b);
	write(1, "rra\n", 4);
	write(1, "rrb\n", 4);
}
