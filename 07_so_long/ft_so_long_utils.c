/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:00:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/12 19:58:28 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_transformaitor(t_data *mlx, int row, int col)
{
	int	x;

	x = 0;
	if (mlx->key == 'S')
		x = row - 1;
	else if (mlx->key == 'W')
		x = row + 1;
	else if (mlx->key == 'A')
		x = col + 1;
	else if (mlx->key == 'D')
		x = col - 1;
	return (x);
}

void	ft_check_key_s_d(t_data *mlx, int row, int col)
{
	int	x;

	x = ft_transformaitor(mlx, row, col);
	if (mlx->key == 'S')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_p,
			col * 50, row * 50);
		if (mlx->map[x][col] != '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
				col * 50, x * 50);
	}
	else if (mlx->key == 'D')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_p,
			col * 50, row * 50);
		if (mlx->map[row][x] != '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
				x * 50, row * 50);
	}
}

void	ft_check_key_a_w(t_data *mlx, int row, int col)
{
	int	x;

	x = ft_transformaitor(mlx, row, col);
	if (mlx->key == 'A')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_p,
			col * 50, row * 50);
		if (mlx->map[row][x] != '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
				x * 50, row * 50);
	}
	else if (mlx->key == 'W')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_p,
			col * 50, row * 50);
		if (mlx->map[x][col] != '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
				col * 50, x * 50);
	}
}

int	ft_get_p_row(t_data *mlx, char c)
{
	int	row;
	int	col;
	int	row_p;

	row = 0;
	while (row < mlx->row_len)
	{
		col = 0;
		while (col < mlx->col_len)
		{
			if (mlx->map[row][col] == c)
			{
				row_p = row;
				return (row_p);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_get_p_col(t_data *mlx, char c)
{
	int	row;
	int	col;
	int	col_p;

	row = 0;
	while (row < mlx->row_len)
	{
		col = 0;
		while (col < mlx->col_len)
		{
			if (mlx->map[row][col] == c)
			{
				col_p = col;
				return (col_p);
			}
			col++;
		}
		row++;
	}
	return (0);
}
