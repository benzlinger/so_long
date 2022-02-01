/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:42:30 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/01 13:08:50 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tile(t_game *game, int x, int y)
{
	int		wid;
	int		hgh;
	void	*img;

	if (game->map[y][x] == '1')
		img = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &wid, &hgh);
	else if (game->map[y][x] == 'E')
		img = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &wid, &hgh);
	else if (game->map[y][x] == 'P' && !game->isP)
	{
		img = mlx_xpm_file_to_image(game->mlx, "sprites/zomb.xpm", &wid, &hgh);
		game->posX = x;
		game->posY = y;
		game->isP = 1;
	}
	else if (game->map[y][x] == 'C')
		img = mlx_xpm_file_to_image(game->mlx, "sprites/brain.xpm", &wid, &hgh);
	else
		img = mlx_xpm_file_to_image(game->mlx, "sprites/tile.xpm", &wid, &hgh);
	mlx_put_image_to_window(game->mlx, game->win, img, x * wid, y * hgh);
}

void	init_territory(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[j][i] != '\n' && game->map[j][i] != '\0')
		{
			init_tile(game, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	game->nCmd = 0;
}
