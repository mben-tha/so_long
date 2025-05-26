/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 10:35:11 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/25 10:44:11 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(char *file)
{
	int		fd;
	char	*line;
	char	*map_line;
	char	**map;

	map_line = ft_strdup("");
	if (!map_line)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(map_line), map_line = NULL, NULL);
	line = get_next_line(fd);
	while (line)
	{
		map_line = ft_strjoin_free(map_line, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close(fd);
	map = ft_split(map_line, '\n');
	return (free(map_line), map_line = NULL, map);
}
