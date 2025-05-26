/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:58:33 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 09:59:55 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	return (ft_strncmp(file + len - 4, ".ber", 4) == 0);
}

void	find_info_backtraking(char **map, t_game *game)
{
	int	x;
	int	y;

	game->collectibles = 0;
	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				game->collectibles++;
			else if (map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
	}
}

int	backtracking(char **map, int y, int x, int C)
{
	char	tmp;

	if (map[y][x] == '1' || (map[y][x] == 'E' && C != 0))
		return (0);
	if (map[y][x] == 'C')
		C--;
	if (map[y][x] == 'E' && C == 0)
		return (1);
	tmp = map[y][x];
	map[y][x] = '1';
	if (backtracking(map, y, x + 1, C) || backtracking(map, y, x - 1, C)
		|| backtracking(map, y + 1, x, C) || backtracking(map, y - 1, x, C))
		return (1);
	map[y][x] = tmp;
	return (0);
}
