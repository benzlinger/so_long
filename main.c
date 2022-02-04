/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:32:22 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/04 15:07:34 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map(char *argv, t_game *game)
{
	int		fd;
	char	*line;

	game->nE = 0;
	game->nC = 0;
	game->nP = 0;
	game->y = get_size(argv);
	init_map(game, argv);
	if (!is_rectangular(game))
		free_map(game);
	if (!is_enclosed(game))
		free_map(game);
	if (!check_chars(game))
		free_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		err_msg(3);
	else if (argc > 2)
		err_msg(4);
	check_map(argv[1], &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.x * 64, game.y * 64, "so_long");
	init_territory(&game);
	mlx_key_hook(game.win, press_button, &game);
	mlx_hook(game.win, 17, 0, free_map, &game);
	mlx_loop(game.mlx);
}
