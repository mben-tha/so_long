#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x = game->player_x + dx;
	int	new_y = game->player_y + dy;
	char	next_tile = game->map[new_y][new_x];

	if (next_tile == '1')
		return; // Mur : pas de déplacement

	if (next_tile == 'E')
	{
		ft_putendl_fd("You win!", 1);
		exit(0);
	}

	if (next_tile == 'C')
		game->map[new_y][new_x] = '0'; // Collecte

	// Mise à jour map
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';

	// Mise à jour position
	// game->player_x = new_x;
	// game->player_y = new_y;

	// Réaffiche
	display_map(game);
}
