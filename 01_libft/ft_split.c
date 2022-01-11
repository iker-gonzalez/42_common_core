/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:26:53 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/07/12 19:26:56 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_div_counter(char const *s, char c)
{
	int	i;
	int	counter;

	counter = 0;
	if (s[0] && s[0] != c)
		counter++;
	i = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			counter++;
		i++;
	}
	return (counter);
}

static char	*ft_segmentator(char const *s, char c, int i)
{
	int		j;
	int		k;
	char	*resultant_string;

	j = i;
	while (s[i] && s[i] != c)
		i++;
	resultant_string = (char *)malloc(sizeof(char) * ((i - j) + 1));
	if (!resultant_string)
		return (NULL);
	k = 0;
	while (j != i)
	{
		resultant_string[k] = s[j];
		k++;
		j++;
	}
	resultant_string[k] = '\0';
	return (resultant_string);
}

int	ft_check_lim(char *s, char c, int i)
{
	int	j;
	int	k;

	k = 0;
	j = i;
	while (s[i] && s[i] != c)
		i++;
	while (j != i)
	{	
		j++;
		k++;
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;	

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (ft_div_counter(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (i <= (int)ft_strlen(s) && ft_div_counter(s, c))
	{
		if (ft_check_lim((char *)s, c, i))
		{
			array[j] = ft_segmentator(s, c, i);
			i += (ft_strlen(array[j]) + 1);
			j++;
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}
