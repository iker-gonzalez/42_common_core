/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:38:36 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 19:37:24 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pos(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}	
}

void	ft_pos_upd(t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

void	ft_rank(t_list *lst)
{
	int		rank;
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp1 = lst;
	tmp2 = lst->next;
	tmp3 = lst;
	while (tmp3 && tmp1)
	{
		tmp1->rank = 0;
		while (tmp2)
		{
			if (tmp1->content > tmp2->content)
			{
				rank++;
				tmp1->rank = rank;
			}
			tmp2 = tmp2->next;
		}
		rank = 0;
		tmp2 = tmp3;
		tmp1 = tmp1->next;
	}
}
