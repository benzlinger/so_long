/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:24:59 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/31 17:25:35 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(int i)
{
	if (i == 0)
	{
		printf("Error\n");
		exit(0);
	}
	else if (i == 1)
	{
		printf("Error. Empty map.\n");
		exit (0);
	}
	else if (i == 2)
	{
		printf("Error. Malloc failed.\n");
		exit (0);
	}
}

static void	init_map(char *line, int fd, t_game *game)
{
	int		i;
	char	**temp;

	while (line)
	{
		temp = game->map;
		game->y++;
		game->map = malloc(sizeof(char *) * (game->y + 1));
		if (!(game->map))
			err_msg(2);
		game->map[(game->y) - 1] = line;
		game->map[game->y] = NULL;
		i = 2;
		while ((game->y) - i >= 0)
		{
			game->map[(game->y) - i] = temp[(game->y) - i];
			i++;
		}
		if (!temp)
			free (temp);
		line = get_next_line(fd);
	}
}

static int	is_enclosed_helper(t_game *game)
{
	int	i;

	i = 1;
	while (i < (game->y - 1))
	{
		if (game->map[i][0] != '1')
			return (0);
		if (game->map[i][game->x - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (game->map[game->y - 1][i])
	{
		if ((game->map[game->y - 1][i]) != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_enclosed(t_game *game)
{
	int	count;

	count = 0;
	while (game->map[0][count] != '\n')
	{
		if ((game->map[0][count]) != '1')
		{
			printf("Error\nMap is not enclosed.\n");
			return (0);
		}
		count++;
	}
	if (!is_enclosed_helper(game))
	{
		printf("Error\nMap is not enclosed.\n");
		return (0);
	}
	return (1);
}

void	check_map(char *argv, t_game *game)
{
	int		fd;
	char	*line;

	game->nE = 0;
	game->nC = 0;
	game->nP = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		err_msg(0);
	line = get_next_line(fd);
	if (!line)
		err_msg(1);
	game->y = 0;
	init_map(line, fd, game);
	close (fd);
	if (!is_rectangular(game))
		free_map(game);
	if (!is_enclosed(game))
		free_map(game);
	if (!check_chars(game))
		free_map(game);
}
