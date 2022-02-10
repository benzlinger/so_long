/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:32:22 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/09 14:22:22 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (size > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			size--;
		}
		else
		{
			return (*s1 - *s2);
		}
	}
	return (0);
}

static void	check_arg(char *argv)
{
	int	count;

	count = 0;
	while (argv[count])
	{
		count++;
	}
	argv += (count - 4);
	if (ft_strncmp(argv, ".ber", 4))
	{
		write(2, "Error\nMap needs to be .ber file\n", 32);
		exit(0);
	}
}

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
	check_arg(argv[1]);
	check_map(argv[1], &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.x * 64, game.y * 64, "so_long");
	init_territory(&game);
	mlx_key_hook(game.win, press_button, &game);
	mlx_hook(game.win, 17, 0, free_map, &game);
	mlx_loop(game.mlx);
}
