/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:23:12 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 19:26:33 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **head_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head_a;
	tmp2 = (*head_a)->next;
	if (!tmp1 || !tmp2)
		return ;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*head_a = tmp2;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **head_b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head_b;
	tmp2 = (*head_b)->next;
	if (!tmp1 || !tmp2)
		return ;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*head_b = tmp2;
	write(1, "sb\n", 3);
}

void	ft_swap_ab(t_list **head_a, t_list **head_b)
{
	if (!*head_a || !*head_b)
		return ;
	ft_swap_a(head_a);
	ft_swap_b(head_b);
	write(1, "ss\n", 3);
}

void	ft_push_a(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (!*head_b)
		return ;
	tmp = *head_b;
	tmp = tmp->next;
	ft_lstadd_front(head_a, *head_b);
	*head_b = tmp;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_list **head_b, t_list **head_a)
{
	t_list	*tmp;

	if (!*head_a)
		return ;
	tmp = *head_a;
	tmp = tmp->next;
	ft_lstadd_front(head_b, *head_a);
	*head_a = tmp;
	write(1, "pb\n", 3);
}
