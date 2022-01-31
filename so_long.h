/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:53:08 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/31 17:53:40 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libmlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		x;
	int		y;
	int		nE;
	int		nC;
	int		nP;
}					t_game;

/* get next line */
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		is_eol(char *s);

/* map */
void	err_msg(int i);
void	check_map(char *argv, t_game *game);

/* map utils */
int		is_rectangular(t_game *game);
int		check_chars(t_game *game);
void	free_map(t_game *game);

/* territory */
void	init_territory(t_game *game);

#endif
