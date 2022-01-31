/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:42:30 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/31 18:01:38 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tile(t_game *game, int x, int y)
{
	int		wid;
	int		hgh;
	void	*img;

	if (game->map[x][y] == '1')
		img = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &wid, &hgh);
	else if (game->map[x][y] == '0')
		img = mlx_xpm_file_to_image(game->mlx, "sprites/tile.xpm", &wid, &hgh);
	else if (game->map[x][y] == 'E')
		img = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &wid, &hgh);
	else if (game->map[x][y] == 'P')
		img = mlx_xpm_file_to_image(game->mlx, "sprites/zombie.xpm", &wid, &hgh);
	else if (game->map[x][y] == 'C')
		img = mlx_xpm_file_to_image(game->mlx, "sprites/brain.xpm", &wid, &hgh);
	mlx_put_image_to_window(game->mlx, game->win, img, x * wid, y * hgh);
}

void	init_territory(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			init_tile(game, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
