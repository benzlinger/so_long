/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:32:22 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/01 14:13:38 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (0);
}
