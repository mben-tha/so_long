/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:16:12 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 21:48:28 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	next_tile = game->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	if (next_tile == 'E' && game->collectibles == 0)
	{
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putendl_fd("\nYou win!", 1);
		close_window(game);
	}
	else if (next_tile == 'E')
		return ;
	game->moves++;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	display_map(game);
}
