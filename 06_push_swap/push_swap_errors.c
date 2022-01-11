/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:31:00 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/24 10:55:02 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_lenght_10(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (0);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (0);
	}
	return (1);
}

int	ft_check_max_lenght(char *str)
{
	int	len;
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	if (len == 10 && !ft_check_lenght_10(str))
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	return (0);
}

void	ft_checknum(char **str, int argc)
{
	int	k;

	k = 0;
	if (str[argc][k] == '.')
		k++;
	while (str[argc])
	{
		ft_check_max_lenght(str[argc]);
		while (str[argc][k])
		{	
			if (!ft_isdigit((str[argc][k])))
			{
				if ((str[argc][k] != '+' || str[argc][k] != '-') &&
					(!ft_isdigit(str[argc][k + 1])))
				{
					write(1, "Error\n", 6);
					exit (0);
				}
			}
			k++;
		}
		k = 0;
		argc++;
	}
}

void	ft_checkrepeat(t_list **head_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head_a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp2->content == tmp1->content)
			{
				write (1, "Error\n", 6);
				exit (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
