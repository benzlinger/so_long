/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:24:59 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/04 15:16:27 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(int i)
{
	if (i == 0)
		printf("Error\n");
	else if (i == 1)
		printf("Error\nEmpty map.\n");
	else if (i == 2)
	{
		printf("Error\nMalloc failed.\n");
		return ;
	}
	else if (i == 3)
		printf("Error\nPlease enter a map.\n");
	else if (i == 4)
		printf("Error\nToo many arguments.\n");
	exit(0);
}

int	get_size(char *argv)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	if (count == 0)
		err_msg(1);
	return (count);
}

void	init_map(t_game *game, char *argv)
{
	int		count;
	int		fd;

	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		err_msg(0);
	game->map = malloc(sizeof(char *) * (game->y + 1));
	if (!game->map)
		err_msg(2);
	while (count <= game->y)
	{
		game->map[count] = get_next_line(fd);
		count++;
	}
	game->map[count] = NULL;
	close(fd);
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

int	is_enclosed(t_game *game)
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
