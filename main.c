/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:32:22 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/28 13:25:34 by btenzlin         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_square(t_data *data, int color)
{
	int	x;
	int	y;

	x = 5;
	y = 5;
	while (x <= 50)
	{
		while (y <= 50)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = 5;
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_data	img;

	if (argc < 2)
		printf("Error. Please enter a map as parameter.\n");
	else if (argc > 2)
		printf("Error. To many parameters.\n");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 500, 500, "mlx_42");
	img.img = mlx_new_image(game.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put_square(&img, 0x00FF0000);
	mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 0);
	mlx_loop(game.mlx);
}
