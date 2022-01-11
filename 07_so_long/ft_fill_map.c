/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:46:44 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/12 20:19:34 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_p(t_data *m, int x, int y)
{
	int			row;
	int			col;

	row = 0;
	y = 0;
	while (row < m->row_len)
	{
		col = 0;
		x = 0;
		while (col < m->col_len)
		{
			if (row == m->p_row && col == m->p_col && m->key == 'Z')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_p, x, y);
			else if (row == m->p_row && col == m->p_col && m->key != 'Z')
			{
				ft_set_key(m);
				ft_move_player(m, row, col);
			}
			x = x + 50;
			col++;
		}
		y = y + 50;
		row++;
	}
}

void	ft_fill_c_e(t_data *m)
{
	int			row;
	int			col;
	static int	x;
	static int	y;

	row = 0;
	y = 0;
	while (row < m->row_len)
	{
		col = 0;
		x = 0;
		while (col < m->col_len)
		{
			if (m->map[row][col] == 'C')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_c, x, y);
			if (m->map[row][col] == 'E')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_e, x, y);
			x = x + 50;
			col++;
		}
		y = y + 50;
		row++;
	}
}

void	ft_fill_1_0(t_data *m)
{
	int			row;
	int			col;
	static int	x;
	static int	y;

	row = 0;
	y = 0;
	while (row < m->row_len)
	{
		col = 0;
		x = 0;
		while (col < m->col_len)
		{
			if (m->map[row][col] == '1')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_1, x, y);
			else if (m->map[row][col] == '0')
				mlx_put_image_to_window(m->mlx, m->mlx_win, m->img_0, x, y);
			x = x + 50;
			col++;
		}
		y = y + 50;
		row++;
	}
}

void	ft_fill_map(t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 50 * mlx->col_len,
			50 * mlx->row_len, "Oh!");
	mlx->img_1 = mlx_xpm_file_to_image(mlx->mlx, "xpm/1.xpm",
			&mlx->width, &mlx->height);
	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx, "xpm/0.xpm",
			&mlx->width, &mlx->height);
	mlx->img_c = mlx_xpm_file_to_image (mlx->mlx, "xpm/c.xpm",
			&mlx->width, &mlx->height);
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx, "xpm/p.xpm",
			&mlx->width, &mlx->height);
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx, "xpm/e.xpm",
			&mlx->width, &mlx->height);
	mlx->p_row = ft_get_p_row(mlx, 'P');
	mlx->p_col = ft_get_p_col(mlx, 'P');
	ft_fill_p(mlx, 0, 0);
	ft_fill_1_0(mlx);
	ft_fill_c_e(mlx);
	ft_hook(mlx);
	mlx_loop(mlx);
}
