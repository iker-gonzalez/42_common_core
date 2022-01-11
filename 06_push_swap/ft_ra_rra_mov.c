/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:23:48 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/23 20:21:09 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra_mov(t_list **head, int part)
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
		if (tmp->part == part)
		{
			tmp->mark = 1;
			ft_reverse_list(head);
			return (mov + 1);
		}
		tmp = tmp->next;
		mov++;
	}
	ft_reverse_list(head);
	return (5000);
}

int	ft_ra_mov(t_list **head, int part)
{
	int		mov;
	t_list	*tmp;

	tmp = *head;
	mov = 0;
	while (tmp)
	{
		if (tmp->part == part)
			return (mov);
		tmp = tmp->next;
		mov++;
	}
	return (5000);
}

int	ft_ra_rra_mov(t_list **lst, int part)
{
	int	ra_mov;
	int	rra_mov;

	ra_mov = ft_ra_mov(lst, part);
	rra_mov = ft_rra_mov(lst, part);
	if (ra_mov + rra_mov == 10000)
		return (2);
	if (ra_mov <= rra_mov)
		return (1);
	else
		return (0);
}
