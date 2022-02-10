/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:03:32 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/09 14:26:54 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(t_game *game)
{
	int	count;

	count = 0;
	if (game->map)
	{
		while (game->map[count])
		{
			free(game->map[count]);
			count++;
		}
		free(game->map);
	}
	exit (0);
}

static size_t	ft_strlen_sl(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

int	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	game->x = ft_strlen_sl(game->map[i]);
	while (game->map[i])
	{
		len = ft_strlen_sl(game->map[i]);
		if (len != game->x)
		{
			write(2, "Error\nMap is not rectangular.\n", 30);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_chars_helper(int e, int c, int p, int fc)
{
	if (e < 1)
	{
		write(2, "Error\nMust be at least 1 exit.\n", 31);
		return (0);
	}
	if (c < 1)
	{
		write(2, "Error\nMust be at least 1 collectible.\n", 38);
		return (0);
	}
	if (p != 1)
	{
		write(2, "Error\nMust be 1 starting position.\n", 35);
		return (0);
	}
	if (!fc)
	{
		write(2, "Error\nForbidden character.\n", 27);
		return (0);
	}
	return (1);
}

int	check_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				game->nE++;
			else if (game->map[i][j] == 'C')
				game->nC++;
			else if (game->map[i][j] == 'P')
				game->nP++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (check_chars_helper(1, 1, 1, 0));
			j++;
		}
		j = 0;
		i++;
	}
	return (check_chars_helper(game->nE, game->nC, game->nP, 1));
}
