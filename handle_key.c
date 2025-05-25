#include "so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC
		exit(0);
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

