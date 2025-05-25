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
}	t_game;

// Fonctions
char	**create_map(char *file);
void	init_game(t_game *game, char *map_file);
void	display_map(t_game *game);
void	free_map(char **map);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);

#endif
