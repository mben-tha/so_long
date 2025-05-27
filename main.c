/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-tha <mben-tha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:46:55 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/27 12:09:32 by mben-tha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.moves = 0;
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./so_long <map_file>", 2);
		return (1);
	}
	game.map = create_map(argv[1]);
	game.cpy_map = create_map(argv[1]);
	if (!game.map || !map_validity(game.map, argv[1]))
	{
		ft_putendl_fd("Invalid map", 2);
		free_map(game.map);
		return (1);
	}
	find_info_backtraking(game.map, &game);
	if (!backtracking(game.cpy_map, game.player_y, game.player_x, game.collectibles))
		return (ft_putendl_fd("Error: back", 2), 0);
	init_game(&game);
	init_image(&game);
	display_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	free_map(game.cpy_map);
	return (0);
}
