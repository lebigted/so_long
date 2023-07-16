/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:45:42 by ltestard          #+#    #+#             */
/*   Updated: 2023/07/15 19:02:14 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(count * size);
	i = 0;
	if (!str)
		return (NULL);
	while (i < (count * size))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

char	*check_stock(char *line, char *stock)
{
	int	i;

	i = 0;
	if (stock && stock[i] != '\0')
	{
		line = ft_strjoin(line, stock);
		ft_right_cutline(line, stock);
	}
	return (line);
}

void	ft_right_cutline(char *line, char *stock)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == '\0')
			break ;
		i++;
	}
	if (line[i] == '\n')
	{
		ft_strcpy(stock, (line + (i + 1)));
		line[i + 1] = 0;
	}
	else
		ft_strcpy(stock, (line + (i)));
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	stock[BUFFER_SIZE + 1];
	char		*line;
	int			r;

	line = ft_strdup("");
	line = check_stock(line, stock);
	while (ft_strchr(line, '\n') == NULL)
	{
		r = (int)read(fd, buffer, BUFFER_SIZE);
		if ((r <= 0 && line[0] == '\0') || r < 0)
		{
			free(line);
			return (NULL);
		}
		if (r == 0)
		{
			return (line);
		}
		buffer[r] = '\0';
		line = ft_strjoin(line, buffer);
		ft_right_cutline(line, stock);
	}
	return (line);
}
