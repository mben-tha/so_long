/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:16:17 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/25 13:22:30 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(char **map)
{
	int	width;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(*map);
	while (*map != NULL)
	{
		if (ft_strlen(*map) != width)
			return (0);
		*map++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_char(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'P' && map[y][x] != 'E')
				return (0);
			x++;
		}
	}
	return (1);
}

int	check_elements(char **map)
{
	int	y;
	int	x;
	int	exit;
	int	player;
	int	collect;

	y = -1;
	exit = 0;
	player = 0;
	collect = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				exit++;
			else if (map[y][x] == 'P')
				player++;
			else if (map[y][x] == 'C')
				collect++;
			x++;
		}
	}
	return (exit == 1 && player == 1 && collect >= 1);
}

int	map_validity(char **map)
{
	if (!check_rectangular(map))
		return (ft_putendl_fd("Error: Map is not rectangular", 2), 0);
	if (!check_walls(map))
		return (ft_putendl_fd("Error: Map must be surrounded by walls", 2), 0);
	if (!check_char(map))
		return (ft_putendl_fd("Error: Map must contain all elements", 2), 0);
	if (!check_elements(map))
		return (ft_putendl_fd("Error: Map must contain all elements", 2), 0);
	return (1);
}
