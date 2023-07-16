/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:40:03 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/15 18:25:31 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y - 1][x] == '1' || (game->map[y - 1][x] == 'E' \
		&& game->comes > 0))
		return ;
	else
	{
		if (game->map[y - 1][x] == 'C')
			game->comes--;
		else if (game->map[y - 1][x] == 'E' && game->comes == 0)
			exit(EXIT_SUCCESS);
		game->map[y - 1][x] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posy = y - 1;
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y + 1][x] == '1' || (game->map[y + 1][x] == 'E' \
		&& game->comes > 0))
		return ;
	else
	{
		if (game->map[y + 1][x] == 'C')
			game->comes--;
		else if (game->map[y + 1][x] == 'E' && game->comes == 0)
			exit(EXIT_SUCCESS);
		game->map[y + 1][x] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posy = y + 1;
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y][x + 1] == '1' || (game->map[y][x + 1] == 'E' \
		&& game->comes > 0))
		return ;
	else
	{
		if (game->map[y][x + 1] == 'C')
			game->comes--;
		else if (game->map[y][x + 1] == 'E' && game->comes == 0)
			exit(EXIT_SUCCESS);
		game->map[y][x + 1] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posx = x + 1;
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y][x - 1] == '1' || (game->map[y][x - 1] == 'E' \
		&& game->comes > 0))
		return ;
	else
	{
		if (game->map[y][x - 1] == 'C')
			game->comes--;
		else if (game->map[y][x - 1] == 'E' && game->comes == 0)
			exit(EXIT_SUCCESS);
		game->map[y][x - 1] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posx = x - 1;
}

int	handle_key(int key_code, t_game *game)
{
	if (key_code == KEY_ECHAP)
		exit(EXIT_SUCCESS);
	if (key_code == KEY_W)
		move_up(game);
	if (key_code == KEY_S)
		move_down(game);
	if (key_code == KEY_A)
		move_left(game);
	if (key_code == KEY_D)
		move_right(game);
	return (0);
}
