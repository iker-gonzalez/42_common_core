/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:42:20 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/13 17:59:49 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize(t_data *m, char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	m->col_len = ft_strlen1((line = get_next_line(fd)));
	free(line);
	close(fd);
	fd = open(str, O_RDONLY);
	m->row_len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		m->row_len++;
	}
	free(line);
	m->c = 0;
	m->key = 'Z';
	m->moves = 0;
	m->exit = 0;
}

int	ft_create_map(t_data *m, char *str)
{
	int		fd;
	int		col;
	int		row;
	char	*line;

	m->map = (char **)malloc(sizeof(char *) * (m->row_len + 1));
	if (!m->map)
		return (0);
	row = 0;
	fd = open(str, O_RDONLY);
	while (row < m->row_len)
	{
		line = get_next_line(fd);
		col = 0;
		m->map[row] = malloc(sizeof(char) * (m->col_len + 1));
		while (col < m->col_len)
		{
			m->map[row][col] = line[col];
			col++;
		}
		free(line);
		m->map[row][col] = '\0';
		row++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	m;
	char	*str;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	str = argv[1];
	ft_initialize(&m, str);
	ft_create_map(&m, str);
	m.col_len -= 1;
	ft_check_ber(str);
	ft_check_errors(&m);
	ft_fill_map(&m);
	return (0);
}
