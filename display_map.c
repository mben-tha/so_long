/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:26:46 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 10:55:10 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_game *game)
{
	int			x;
	int			y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
				x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'P')
				display_player(game, y, x);
		}
	}
}

void	display_player(t_game *game, int y, int x)
{
	game->player_x = x;
	game->player_y = y;
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		x * TILE_SIZE, y * TILE_SIZE);
}
