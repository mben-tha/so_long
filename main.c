#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./so_long <map_file>", 2);
		return (1);
	}
	init_game(&game, argv[1]);
	display_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
