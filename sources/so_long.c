/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:21:24 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/15 17:35:30 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*image(t_game *game, char *img)
{
	int		img_w;
	int		img_h;
	void	*image;

	image = mlx_xpm_file_to_image(game->mlxwin, img, &img_w, &img_h);
	if (!image)
		handle_error(4);
	return (image);
}

void	create_window(t_game *game)
{
	game->mlxwin = mlx_init();
	game->window = mlx_new_window(game->mlxwin, game->xlong * 50, \
		game->ylong * 50, "Hello bro");
	game->floor = image(game, "./xpm/floor.xpm");
	game->character = image(game, "./xpm/char.xpm");
	game->wall = image(game, "./xpm/wall.xpm");
	game->object = image(game, "./xpm/object.xpm");
	game->f_exit = image(game, "./xpm/f_exit.xpm");
}

void	player_move(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	mlx_put_image_to_window(game->mlxwin, game->window, \
		game->character, x * 50, y * 50);
}

void	init_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->floor, x * 50, y * 50);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->wall, x * 50, y * 50);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->object, x * 50, y * 50);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->f_exit, x * 50, y * 50);
		}
	}
	player_move(game);
}
