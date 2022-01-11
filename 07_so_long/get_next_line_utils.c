/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:13:29 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/13 17:57:57 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen2(char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	return (i);
}

int	check_line_break(char *buff)
{
	int	i;

	if (!buff)
		return (0);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*join;
	int		join_len;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	join_len = ft_strlen2(s1, '\0') + ft_strlen2(s2, '\0') + 1;
	join = malloc(sizeof(char) * join_len);
	if (!join)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
		join[i++] = s1[k++];
	k = 0;
	while (i < join_len - 1)
		join[i++] = s2[k++];
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*ft_substr(char const *buff, unsigned int start, size_t end)
{
	char	*line;
	size_t	i;
	size_t	k;

	line = malloc(sizeof(char) * (end + 1));
	if (!line || !buff)
		return (NULL);
	i = 0;
	k = 0;
	while (buff[i])
	{
		if (i >= start && k < end)
		{
			line[k] = buff[i];
			k++;
		}
		i++;
	}
	line[k] = '\0';
	return (line);
}

char	*ft_substr2(char *buff, unsigned int start, size_t end)
{
	char	*line;
	size_t	i;
	size_t	k;

	if (!check_line_break(buff))
	{	
		free(buff);
		return (NULL);
	}
	line = malloc(sizeof(char) * (end + 1));
	if (!line || !buff)
		return (NULL);
	i = 0;
	k = 0;
	while (buff[i])
	{
		if (i >= start && k < end)
			line[k++] = buff[i];
		i++;
	}
	line[k] = '\0';
	free(buff);
	return (line);
}
