/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:41:37 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/15 19:32:07 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	verify_walls(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if ((game->map[0][x] != '1' \
				|| game->map[game->ylong - 1][x] != '1') \
				&& game->map[0][x] != '\n')
				handle_error(0);
			if (game->map[y][0] != '1' || game->map[y][game->xlong - 1] != '1')
				handle_error(0);
		}
	}
}

void	validate_rec(t_game *game)
{
	int		i;
	size_t	first;

	i = -1;
	first = ft_strlen(game->map[0]);
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != 0 && first != ft_strlen(game->map[i]))
			handle_error(1);
		if (ft_strlen(game->map[i]) == 0 && game->map[i + 1] \
			&& ft_strlen(game->map[i + 1]) == 0)
			handle_error(2);
	}
}

void	validate_char(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				game->comes++;
			else if (game->map[y][x] == 'E')
				game->exit++;
			else if (game->map[y][x] == 'P')
				game->player++;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1' \
				&& game->map[y][x] != '\n')
				handle_error(6);
		}
	}
	if (game->comes < 1 || game->exit != 1 || game->player != 1)
		handle_error(5);
}

void	parse_game(t_game *game, char *av)
{
	int	*tab;

	proc_map(av, game);
	init_struct(game);
	validate_rec(game);
	verify_walls(game);
	validate_char(game);
	copy_map(game);
	tab = find_player(game);
	initial_path(game, tab[0], tab[1]);
	validate_path(game);
	free(tab);
}
