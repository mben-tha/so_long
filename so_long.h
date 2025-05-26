/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:38:07 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 10:55:41 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# define TILE_SIZE 32

typedef struct s_game
{
	void	*mlx;
	void	*win;

	void	*floor_img;
	void	*wall_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;

	int		map_width;
	int		map_height;

	int		player_x;
	int		player_y;

	int		collectibles;

	char	**map;
	char	**cpy_map;
}	t_game;

char	**create_map(char *file);
void	free_map(char **map);
int		check_rectangular(char **map);
int		check_walls(char **map);
int		check_char(char **map);
int		check_elements(char **map);
int		map_validity(char **map);
void	find_info_backtraking(char **map, t_game *game);
int		backtracking(char **map, int y, int x, int C);
void	init_game(t_game *game);
void	init_image(t_game *game);
void	display_map(t_game *game);
void	display_player(t_game *game, int y, int x);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);

#endif
