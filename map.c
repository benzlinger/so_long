/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:24:59 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/09 14:29:57 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(int i)
{
	if (i == 0)
		write(2, "Error\n", 6);
	else if (i == 1)
		write(2, "Error\nEmpty map.\n", 17);
	else if (i == 2)
	{
		write(2, "Error\nMalloc failed.\n", 21);
		return ;
	}
	else if (i == 3)
		write(2, "Error\nPlease enter a map.\n", 26);
	else if (i == 4)
		write(2, "Error\nToo many arguments.\n", 26);
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
			write(2, "Error\nMap is not surrounded by walls.\n", 38);
			return (0);
		}
		count++;
	}
	if (!is_enclosed_helper(game))
	{
		write(2, "Error\nMap is not surrounded by walls.\n", 38);
		return (0);
	}
	return (1);
}
