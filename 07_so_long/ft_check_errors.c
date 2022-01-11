/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:51:47 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/13 18:08:35 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_perimeter(t_data *m)
{
	int	row;
	int	col;

	row = 0;
	while (row < m->row_len)
	{
		col = 0;
		while (col < m->col_len)
		{
			if (m->map[0][col] != '1' || m->map[m->row_len - 1][col] != '1')
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			else if (m->map[row][0] != '1'
							|| m->map[row][m->col_len - 1] != '1')
			{
				write (1, "Error\n", 6);
				exit (0);
			}
			col++;
		}
		row++;
	}
}

void	ft_check_values3(t_data *m, int row)
{
	int	col;

	while (row < m->row_len)
	{
		col = 0;
		while (col < m->col_len)
		{
			if (m->map[row][col] != '0' && m->map[row][col] != '1'
					&& m->map[row][col] != 'C' && m->map[row][col] != 'P'
					&& m->map[row][col] != 'E')
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			col++;
		}
		row++;
	}
}

void	ft_check_values2(t_data *m, int row)
{
	int	col;
	int	p;

	p = 0;
	while (row < m->row_len)
	{
		col = 0;
		while (col < m->col_len)
		{
			if (m->map[row][col] == 'P')
				p++;
			col++;
		}
		row++;
	}
	if (p > 1)
	{
		write (1, "Error\n", 6);
		exit (0);
	}
}

void	ft_check_values1(t_data *m, int row)
{
	int	e;
	int	col;

	e = 0;
	while (row < m->row_len)
	{
		col = 0;
		while (col < m->col_len)
		{
			if (m->map[row][col] == 'C')
				m->c++;
			else if (m->map[row][col] == 'E')
				e++;
			col++;
		}
		row++;
	}
	if (e > 1 || m->c < 1)
	{
		write (1, "Error\n", 6);
		exit (0);
	}
}

void	ft_check_errors(t_data *mlx)
{
	ft_check_perimeter(mlx);
	ft_check_values1(mlx, 0);
	ft_check_values2(mlx, 0);
	ft_check_values3(mlx, 0);
}
