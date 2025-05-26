#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./so_long <map_file>", 2);
		return (1);
	}
	game.map = create_map(argv[1]);
	game.cpy_map = create_map(argv[1]);
	if (!game.map || !map_validity(game.map))
	{
		ft_putendl_fd("Invalid map", 2);
		free_map(game.map);
		return (1);
	}
	find_info_backtraking(game.map, &game);
	backtracking(game.cpy_map, game.player_y, game.player_x, game.collectibles);
	init_game(&game);
	init_image(&game);
	display_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	free_map(game.cpy_map);
	return (0);
}
