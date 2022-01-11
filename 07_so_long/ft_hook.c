/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:35:20 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/13 17:58:55 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

void	ft_moves(t_data *mlx)
{
	int			prev_x;
	int			prev_y;
	static int	moves;

	prev_x = mlx->p_row;
	prev_y = mlx->p_col;
	ft_fill_p2(mlx);
	if (prev_x != mlx->p_row || prev_y != mlx->p_col)
		printf("moves = %d \n", ++moves);
}

int	key_hook(int key, t_data *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		ft_free_map(&mlx);
		exit(0);
	}
	else if (key == 1)
		mlx->key = 'S';
	else if (key == 13)
		mlx->key = 'W';
	else if (key == 0)
		mlx->key = 'A';
	else if (key == 2)
		mlx->key = 'D';
	else
		mlx->key = 'Z';
	if (mlx->key == 'A' || mlx->key == 'S'
		|| mlx->key == 'W' || mlx->key == 'D')
		ft_moves(mlx);
	return (0);
}

int	ft_hook(t_data *mlx)
{
	mlx_hook(mlx->mlx_win, 2, (1L << 0), key_hook, mlx);
	mlx_hook(mlx->mlx_win, 17, (1L << 8), close_window, mlx);
	return (0);
}
