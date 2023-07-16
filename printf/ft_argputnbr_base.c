/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argputnbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:18:53 by ltestard          #+#    #+#             */
/*   Updated: 2023/01/20 17:05:30 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_argputnbr_base(unsigned int n, int d, int *res)
{
	char	*base;
	char	c;

	if (d == 0)
		base = "0123456789abcdef";
	if (d == 1)
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		forma_my_nbrbase((n / 16), base, res);
		forma_my_nbrbase((n % 16), base, res);
	}
	if (n < 16)
	{
		c = base[n];
		forma_my_char(c, res);
	}
}
