/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:12:05 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/15 19:32:20 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game_obj(t_game *game)
{
	game->map = NULL;
	game->line.x = 0;
	game->line.y = 0;
	game->ylong = 0;
	game->xlong = 0;
	game->player = 0;
	game->comes = 0;
	game->exit = 0;
	game->verif_comes = 0;
	game->verif_exit = 0;
	game->mapcpy = 0;
	game->step = 0;
}

static unsigned int	count_lines(const char *file)
{
	char			*inputline;
	unsigned int	linecount;
	int				filedescriptor;

	filedescriptor = open(file, O_RDONLY);
	if (filedescriptor < 0)
		handle_error(8);
	inputline = get_next_line(filedescriptor);
	linecount = 0;
	while (inputline != NULL)
	{
		linecount++;
		free(inputline);
		inputline = get_next_line(filedescriptor);
	}
	close(filedescriptor);
	return (linecount);
}

void	init_struct(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i] && game->map != NULL)
		game->ylong++;
	game->xlong = ft_strlen(game->map[0]) - 1;
}

void	proc_map(const char *file, t_game *game)
{
	char	*inputline;
	int		lineindex;
	int		filedescriptor;

	game->line.y = count_lines(file);
	filedescriptor = open(file, O_RDONLY);
	inputline = get_next_line(filedescriptor);
	if (!inputline)
		handle_error(8);
	game->line.x = ft_strlen(inputline);
	game->map = malloc(sizeof(char *) * (game->line.y + 1));
	if (!game->map)
		return ;
	lineindex = 0;
	while (inputline != NULL)
	{
		game->map[lineindex] = inputline;
		inputline = get_next_line(filedescriptor);
		lineindex++;
	}
	close(filedescriptor);
	game->map[lineindex] = NULL;
	if (*game->map == NULL)
		handle_error(8);
}
