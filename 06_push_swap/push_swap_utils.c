/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 06:56:30 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 19:14:39 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sizeof_chunk(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_sorted(t_list *lst)
{
	while (lst-> next)
	{
		if (lst->content > lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	ft_biggest_content(t_list *lst)
{
	int	biggest;

	biggest = lst->content;
	while (lst != NULL)
	{
		if (biggest < lst->content)
			biggest = lst->content;
		lst = lst->next;
	}
	return (biggest);
}

void	ft_small(t_list **lst)
{
	t_list	*ref;
	int		i;

	ref = *lst;
	i = 0;
	while (ref != NULL && i < 2)
	{
		if (ref->rank == 0 | ref->rank == 1)
		{
			ref->mark = 1;
			i++;
		}
		ref = ref->next;
	}
}

int	ft_smallest_content(t_list *lst)
{
	int		smallest;
	t_list	*tmp;

	tmp = lst;
	if (lst->mark != 1)
		smallest = lst->content;
	while (lst != NULL)
	{
		if (smallest >= lst->content && lst->mark != 1)
		{
			smallest = lst->content;
			lst->mark = 1;
		}
		lst = lst->next;
	}
	while (tmp != NULL)
	{
		if (tmp->content != smallest)
			tmp->mark = 0;
		tmp = tmp->next;
	}
	return (smallest);
}
