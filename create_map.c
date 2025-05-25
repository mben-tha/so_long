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
	{
		free(map_line);
		return (NULL);
	}
	while ((line = get_next_line(fd)))
	{
		map_line = ft_strjoin_free(map_line, line);
		free(line);
	}
	close(fd);
	map = ft_split(map_line, '\n');
	free(map_line);
	return (map);
}
