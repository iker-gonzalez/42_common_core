/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:45:24 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/12 19:58:32 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_if_no(t_data *mlx)
{
	if (mlx->key == 'S')
		mlx->p_row -= 1;
	if (mlx->key == 'W')
		mlx->p_row += 1;
	if (mlx->key == 'A')
		mlx->p_col += 1;
	if (mlx->key == 'D')
		mlx->p_col -= 1;
}

void	ft_check_if_c(t_data *mlx, int row, int col)
{
	if (mlx->map[mlx->p_row][mlx->p_col] == 'C')
	{
		mlx->map[mlx->p_row][mlx->p_col] = 0;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0, col * 50,
			row * 50);
		mlx->c--;
	}	
	if (mlx->c == 0 && mlx->exit == 0)
	{
		mlx->exit = 1;
		mlx->e_row = ft_get_p_row(mlx, 'E');
		mlx->e_col = ft_get_p_col(mlx, 'E');
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_0,
			mlx->e_col * 50, mlx->e_row * 50);
		mlx->img_y = mlx_xpm_file_to_image(mlx->mlx, "xpm/y.xpm",
				&mlx->width, &mlx->height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_y,
			mlx->e_col * 50, mlx->e_row * 50);
	}
}

void	ft_move_player(t_data *mlx, int row, int col)
{
	ft_check_if_c(mlx, row, col);
	if (mlx->map[mlx->p_row][mlx->p_col] == 'E' && mlx->exit == 0)
		ft_set_if_no(mlx);
	else if (mlx->map[mlx->p_row][mlx->p_col] == 'E' && mlx->exit == 1)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	else if (mlx->map[mlx->p_row][mlx->p_col] != '1')
	{
		ft_check_key_s_d(mlx, row, col);
		ft_check_key_a_w(mlx, row, col);
	}
	else
		ft_set_if_no(mlx);
}
