/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:43:27 by ltestard          #+#    #+#             */
/*   Updated: 2023/07/15 17:10:47 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int lookc)
{
	char	i;

	i = lookc;
	if (i == '\0')
	{
		while (*str)
		{
			str++;
		}
		return ((char *)str);
	}
	while (*str)
	{
		if (*str == i)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	while (j < i)
	{
		res[j] = src[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ouii;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = (char *)s1;
	ouii = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ouii)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		ouii[i] = *str;
		str++;
		i++;
	}
	while (*s2 != '\0')
		ouii[i++] = *s2++;
	ouii[i] = '\0';
	free(s1);
	return (ouii);
}
