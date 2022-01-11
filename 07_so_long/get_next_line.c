/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:13:25 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/13 17:56:54 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	char		buff[11];
	int			bytes_read;
	static char	*rest;
	char		*line;

	if (fd < 0)
		return (NULL);
	bytes_read = 1;
	while (!check_line_break(rest) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, 10);
		if (bytes_read == -1)
			return (NULL);
		buff[bytes_read] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	line = ft_substr(rest, 0, ft_strlen2(rest, '\n') + 1);
	rest = ft_substr2(rest, ft_strlen2(line, '\0'),
			ft_strlen2(rest, '\0') - ft_strlen2(line, '\0'));
	if (bytes_read == 0 && ft_strlen2(line, '\0') == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
