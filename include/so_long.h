/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:02:19 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/15 19:04:16 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <string.h>
# include <mlx.h>

# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_ECHAP 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_game
{
	char	**map;
	char	**mapcpy;
	void	*window;
	void	*mlxwin;
	t_pos	line;
	int		xlong;
	int		ylong;
	int		player;
	int		exit;
	int		comes;
	int		verif_comes;
	int		verif_exit;
	void	*floor;
	void	*character;
	void	*wall;
	void	*object;
	void	*f_exit;
	int		player_posy;
	int		player_posx;
	int		step;
}				t_game;

void	proc_map(const char *file, t_game *game);
void	init_game_obj(t_game *game);
void	validate_rec(t_game *game);
void	verify_walls(t_game *game);
void	parse_game(t_game *game, char *av);
void	init_struct(t_game *game);
void	handle_error(int er);
void	validate_char(t_game *game);
int		copy_map(t_game *game);
void	initial_path(t_game *game, int y, int x);
void	validate_path(t_game *game);
int		*find_player(t_game *game);
void	confirm_ext(char *ber);
void	create_window(t_game *game);
void	init_image(t_game *game);
int		handle_key(int key_code, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(const char *str, int lookc);
char	*ft_strdup(const char *src);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
char	*check_stock(char *line, char *stock);
void	ft_right_cutline(char *line, char *stock);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif