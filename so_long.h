/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-tha <mben-tha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:38:07 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/27 11:33:36 by mben-tha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

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

	int		moves;
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
int		map_validity(char **map, const char *file);
void	find_info_backtraking(char **map, t_game *game);
int		backtracking(char **map, int y, int x, int C);
int		check_ber(const char *file);
void	init_game(t_game *game);
void	init_image(t_game *game);
void	display_map(t_game *game);
void	display_player(t_game *game, int y, int x);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		close_window(t_game *game);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
ssize_t	ft_read(char **stock, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_line(char **stock);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_countwords(char const *s, char c);
size_t	ft_len_word(char const *s, char c);
char	*ft_mall(char const *s, char c);
int	fr(char **result, size_t i);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);

#endif
