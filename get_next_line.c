/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-tha <mben-tha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:51:25 by mben-tha          #+#    #+#             */
/*   Updated: 2025/05/27 11:03:49 by mben-tha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_line(char **stock)
{
	char	*line;
	char	*tmp;
	size_t	len;
	char	*position;

	position = ft_strchr(*stock, '\n');
	if (position == NULL)
	{
		line = *stock;
		*stock = NULL;
		return (line);
	}
	len = position - *stock + 1;
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	line[len] = '\0';
	while (--len + 1 > 0)
		line[len] = (*stock)[len];
	tmp = ft_strdup(position + 1);
	free(*stock);
	*stock = tmp;
	return (line);
}

ssize_t	ft_read(char **stock, int fd)
{
	char	*buff;
	ssize_t	bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes <= 0)
		return (free(buff), buff = NULL, bytes);
	buff[bytes] = '\0';
	*stock = ft_strjoin_free(*stock, buff);
	free(buff);
	buff = NULL;
	if (*stock == NULL)
		return (-1);
	return (bytes);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes;
	static char	*stock;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (ft_strchr(stock, '\n') == NULL)
	{
		bytes = ft_read(&stock, fd);
		if (bytes == 0 && stock && *stock)
			return (ft_line(&stock));
		if (bytes <= 0)
		{
			free(stock);
			stock = NULL;
			return (NULL);
		}
	}
	return (ft_line(&stock));
}
