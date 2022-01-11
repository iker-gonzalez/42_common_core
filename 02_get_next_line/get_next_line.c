/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:13:25 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/09/13 19:56:10 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	int			bytes_read;
	static char	*rest;
	char		*line;

	if (fd < 0)
		return (NULL);
	bytes_read = 1;
	while (!check_line_break(rest) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buff[bytes_read] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	line = ft_substr(rest, 0, ft_strlen(rest, '\n') + 1);
	rest = ft_substr2(rest, ft_strlen(line, '\0'),
			ft_strlen(rest, '\0') - ft_strlen(line, '\0'));
	if (bytes_read == 0 && ft_strlen(line, '\0') == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
