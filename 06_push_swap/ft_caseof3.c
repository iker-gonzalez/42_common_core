/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caseof3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:54:16 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/24 11:16:32 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_caseof3(t_list **lst)
{
	int	k;
	int	j;
	int	h;

	k = (*lst)->content;
	j = (*lst)->next->content;
	h = (*lst)->next->next->content;
	if (k > j && j < h && h > k)
		ft_swap_a(lst);
	if (k > j && j > h && h < k)
	{
		ft_swap_a(lst);
		ft_reverse_a(lst);
	}
	if (k > j && j < h && h < k)
		ft_rotate_a(lst);
	if (k < j && j > h && h > k)
	{
		ft_swap_a(lst);
		ft_rotate_a(lst);
	}
	if (k < j && j > h && h < k)
		ft_reverse_a(lst);
}
