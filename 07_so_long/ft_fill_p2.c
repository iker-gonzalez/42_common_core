/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:24:49 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/12 19:58:34 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_key(t_data *mlx)
{
	if (mlx->key == 'S')
		mlx->p_row += 1;
	if (mlx->key == 'W')
		mlx->p_row -= 1;
	if (mlx->key == 'A')
		mlx->p_col -= 1;
	if (mlx->key == 'D')
		mlx->p_col += 1;
}

void	ft_fill_p2(t_data *mlx)
{
	int			row;
	int			col;
	static int	x;
	static int	y;

	row = 0;
	y = 0;
	ft_set_key(mlx);
	while (row < mlx->row_len)
	{
		col = 0;
		x = 0;
		while (col < mlx->col_len)
		{
			if (row == mlx->p_row && col == mlx->p_col)
				ft_move_player(mlx, row, col);
			x = x + 50;
			col++;
		}
		y = y + 50;
		row++;
	}
}
