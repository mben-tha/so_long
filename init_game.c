/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:12:47 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 10:15:48 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	height;
	int	width;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putendl_fd("Error: mlx_init failed", 2);
		exit(1);
	}
	height = 0;
	width = 0;
	while (game->map[height])
		height++;
	if (height > 0)
		width = ft_strlen(game->map[0]);
	game->map_height = height;
	game->map_width = width;
	game->win = mlx_new_window(game->mlx, width * TILE_SIZE,
			height * TILE_SIZE, "so_long");
}

void	init_image(t_game *game)
{
	int	height;
	int	width;

	height = game->map_height;
	width = game->map_width;
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &width, &height);
	game->collect_img = mlx_xpm_file_to_image(game->mlx,
			"assets/collect.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &width, &height);
	if (!game->floor_img || !game->wall_img || !game->player_img
		|| !game->collect_img || !game->exit_img)
	{
		ft_putendl_fd("Error: failed to load images", 2);
		exit(1);
	}
}
