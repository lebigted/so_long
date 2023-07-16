/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:05:52 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/15 19:11:14 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	confirm_ext(char *ber)
{
	int	i;

	i = ft_strlen(ber);
	if ((ber[i - 4] != '.') || (ber[i - 3] != 'b') || (ber[i - 2] != 'e') \
		|| (ber[i - 1] != 'r'))
		handle_error (4);
}

int	loop(t_game *game)
{
	init_image(game);
	return (0);
}

void	handle_error(int er)
{
	if (er == 0)
		ft_printf("Error\nnot walls\n");
	if (er == 1)
		ft_printf("Error\nnot rectangular map\n");
	if (er == 2)
		ft_printf("Error\ninvalid map\n");
	if (er == 3)
		ft_printf("Error\narguments\n");
	if (er == 4)
		ft_printf("Error\nnot good file\n");
	if (er == 5)
		ft_printf("Error\ninvalid char\n");
	if (er == 6)
		ft_printf("Error\nYou are not char\n");
	if (er == 7)
		ft_printf("Error\nproblem path\n");
	if (er == 8)
		ft_printf("Error\nmap\n");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		handle_error(3);
	confirm_ext(av[1]);
	init_game_obj(&game);
	parse_game(&game, av[1]);
	create_window(&game);
	mlx_loop_hook(game.mlxwin, &loop, &game);
	mlx_hook(game.window, 2, 0, &handle_key, &game);
	mlx_loop(game.mlxwin);
}
