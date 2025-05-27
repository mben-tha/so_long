/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-tha <mben-tha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:12:44 by mben-tha          #+#    #+#             */
/*   Updated: 2025/05/27 11:36:59 by mben-tha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

size_t	ft_len_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	*ft_mall(char const *s, char c)
{
	size_t		i;
	char		*dest;

	i = 0;
	dest = malloc((ft_len_word(s, c) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i] != c && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	fr(char **result, size_t i)
{
	if (result[i] == NULL)
	{
		while (i > 0)
		{
			i--;
			free(result[i]);
		}
		free(result);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**result;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	result = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			result[i++] = ft_mall(&s[j], c);
			if (fr(result, i - 1))
				return (NULL);
			j += ft_len_word(&s[j], c);
		}
	}
	result[i] = 0;
	return (result);
}
