/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:23:12 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 19:29:49 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **head_a)
{
	t_list	*tmp;

	if (!*head_a)
		return ;
	tmp = *head_a;
	*head_a = tmp->next;
	ft_lstadd_back(head_a, tmp);
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_list **head_b)
{
	t_list	*tmp;

	if (!*head_b)
		return ;
	tmp = *head_b;
	*head_b = tmp->next;
	ft_lstadd_back(head_b, tmp);
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rotate_a_b(t_list **head_a, t_list **head_b)
{
	if (!*head_a || *head_b)
		return ;
	ft_rotate_a(head_a);
	ft_rotate_b(head_b);
	write(1, "ra\n", 3);
	write(1, "rb\n", 3);
}
