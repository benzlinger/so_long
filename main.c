/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:32:22 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/31 18:01:10 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	ft_close(int keycode, t_game game)
{
	if (keycode == 53)
		mlx_destroy_window(game.mlx, game.win);
	return (0);
}

int	ft_close_x(int keycode, t_game game)
{
	mlx_destroy_window(game.mlx, game.win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_key_hook(int	keycode, t_game game)
{
	printf("Key pressed. %d\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_data	img;

	if (argc < 2)
		printf("Error: Please enter a map as parameter.\n");
	else if (argc > 2)
		printf("Error: To many parameters.\n");
	check_map(argv[1], &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.x * 64, game.y * 64, "so_long");
	init_territory(&game);
	// // mlx_key_hook(game.win, ft_key_hook, &game);
	// // mlx_hook(game.win, 2, 1L << 0, ft_close, &game);
	// // mlx_hook(game.win, 17, 0, ft_close_x, &game);
	mlx_loop(game.mlx);
	return (0);
}
