/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:14:25 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 22:03:19 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC
		close_window(game);
	else if (keycode == 119 || keycode == 65362) // W or ↑
		move_player(game, 0, -1);
	else if (keycode == 115 || keycode == 65364) // S or ↓
		move_player(game, 0, 1);
	else if (keycode == 97 || keycode == 65361)  // A or ←
		move_player(game, -1, 0);
	else if (keycode == 100 || keycode == 65363) // D or →
		move_player(game, 1, 0);
	return (0);
}

int	close_window(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->cpy_map)
		free_map(game->cpy_map);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

