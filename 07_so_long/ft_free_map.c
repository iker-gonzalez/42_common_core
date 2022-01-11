/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:26:48 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/12 14:05:13 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_data **mlx)
{
	int	row;

	row = 0;
	while (row < (*mlx)->row_len)
	{
		free((*mlx)->map[row]);
		row++;
	}
	free((*mlx)->map);
}
