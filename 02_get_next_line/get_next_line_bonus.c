/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:13:25 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/09/13 20:16:28 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	int			bytes_read;
	static char	*rest[4096];
	char		*line;

	if (fd < 0)
		return (NULL);
	bytes_read = 1;
	while (!check_line_break(rest[fd]) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buff[bytes_read] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buff);
	}
	line = ft_substr(rest[fd], 0, ft_strlen(rest[fd], '\n') + 1);
	rest[fd] = ft_substr2(rest[fd], ft_strlen(line, '\0'),
			ft_strlen(rest[fd], '\0') - ft_strlen(line, '\0'));
	if (bytes_read == 0 && ft_strlen(line, '\0') == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
