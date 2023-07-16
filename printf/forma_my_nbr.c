/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forma_my_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:17:35 by ltestard          #+#    #+#             */
/*   Updated: 2023/01/20 17:04:22 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	forma_my_nbr(int nb, int *res)
{
	if (nb == -2147483648)
	{
		forma_my_putstr("-2147483648", res);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		forma_my_char('-', res);
	}
	if (nb > 9)
	{
		forma_my_nbr(nb / 10, res);
		forma_my_nbr(nb % 10, res);
	}
	else
	{
		forma_my_char(nb + '0', res);
	}
}

void	forma_my_nbrbase(unsigned long nb, char *base, int *res)
{
	if (nb >= 16)
	{
		forma_my_nbrbase((nb / 16), base, res);
		forma_my_nbrbase((nb % 16), base, res);
	}
	else
	{
		forma_my_char(base[nb], res);
	}
}

void	forma_my_nbr_ten(unsigned int nb, int *res)
{
	if (nb > 9)
	{
		forma_my_nbr(nb / 10, res);
		forma_my_nbr(nb % 10, res);
	}
	else
	{
		forma_my_char(nb + '0', res);
	}
}
