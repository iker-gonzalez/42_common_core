/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:20:25 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/15 14:01:48 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	background;
}				t_zone;

typedef struct s_shape
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	background;
}				t_shape;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*paint_zone(t_zone *zone)
{
	char	*drawing;
	int		i;

	drawing = malloc(sizeof(char) * (zone->width * zone->height));
	if (!drawing)
		return (NULL);
	i = 0;
	while (i < zone->width * zone->height)
	{
		drawing[i] = zone->background;
		printf("%c", drawing[i]);
		i++;
	}
	return (drawing);
}

int	check_zone(t_zone *zone)
{
	if (zone->width > 0 && zone->width <= 300 && zone->height > 0
		&& zone->width <= 0)
		return (1);
	return (0);
}

int	get_zone(FILE *file, t_zone *zone)
{
	int	scan_ret;

	scan_ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height,
			&zone->background);
	if (scan_ret != 3 || scan_ret == -1)
		return (0);
	else if (!check_zone(zone))
		return (0);
	return (1);
}

int	ft_error(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int	draw_shapes(FILE *file, char **drawing, t_zone *zone)
{
	t_shape	tmp;
	int		scan_ret;

	while (fscanf(file, "%c %f %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y,
			&tmp.width, &tmp.height, &tmp.background) == 6)
	if (scan_ret != 6)
		return (0);
}

int	main(int argc, char **argv)
{
	t_zone	zone;
	FILE	*file;
	char	*drawing;

	zone.width = 0;
	zone.height = 0;
	zone.background = 0;
	if (argc != 2)
		return (ft_error("Error: number of arguments\n", 1));
	file = fopen(argv[1], "r");
	if (!file)
		return (ft_error("Error: opening file\n", 1));
	get_zone(file, &zone);
	drawing = paint_zone(&zone);
	
}
