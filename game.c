/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:13:53 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/03 15:04:05 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int x, int y)
{
	if (game->map[game->posY + y][game->posX + x] == '1')
		return ;
	else if (game->map[game->posY + y][game->posX + x] == 'E' && game->nC)
		return ;
	else if (game->map[game->posY + y][game->posX + x] == 'C' && game->nC)
		game->nC--;
	game->map[game->posY][game->posX] = '0';
	init_tile(game, game->posX, game->posY);
	printf("%d\n", ++(game->nCmd));
	game->isP = 0;
	game->posY += y;
	game->posX += x;
	if (game->map[game->posY][game->posX] == 'E')
		free_map(game);
	game->map[game->posY][game->posX] = 'P';
	init_tile(game, game->posX, game->posY);
}

int	press_button(int keycode, t_game *game)
{
	if (keycode == 13)
		move_player(game, 0, -1);
	else if (keycode == 0)
		move_player(game, -1, 0);
	else if (keycode == 1)
		move_player(game, 0, 1);
	else if (keycode == 2)
		move_player(game, 1, 0);
	else if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_map(game);
	}
	return (0);
}
