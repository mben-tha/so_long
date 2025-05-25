#include "so_long.h"

void	display_map(t_game *game)
{
	int	x;
	int	y;
	char	tile;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			tile = game->map[y][x];

			mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);

			if (tile == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
