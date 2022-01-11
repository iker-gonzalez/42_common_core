/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:22:40 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/24 10:54:31 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_newnode(t_list **head_a, size_t num)
{
	t_list	*new;

	new = NULL;
	new = ft_lstnew(num);
	new->mark = 0;
	new->pos = 0;
	new->rank = 0;
	new->part = 0;
	ft_lstadd_back(head_a, new);
}

void	ft_check_args(int argc, char **argv, t_list **head_a)
{
	int		i;
	char	**array;

	i = 1;
	if (argc != 2)
	{	
		ft_checknum(argv, 1);
		while (i < argc)
			ft_newnode(head_a, ft_atoi(argv[i++]));
	}
	else
	{
		array = ft_split(argv[1], ' ');
		ft_checknum(array, 0);
		i = 0;
		while (array[i])
			ft_newnode(head_a, ft_atoi(array[i++]));
	}
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (1);
	ft_check_args(argc, argv, &head_a);
	ft_checkrepeat(&head_a);
	if (!ft_sorted(head_a))
		exit (0);
	ft_pos(head_a);
	ft_rank(head_a);
	ft_distribution(&head_a, &head_b, ft_sizeof_chunk(head_a));
	ft_free(&head_a);
	ft_free(&head_b);
	return (0);
}
