/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:44:10 by ltestard          #+#    #+#             */
/*   Updated: 2023/07/14 14:52:45 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_printf(const char *parms, ...)
{
	va_list	p_arg;
	int		i;
	int		result[1];

	va_start(p_arg, parms);
	i = 0;
	*result = 0;
	while (parms[i])
	{
		if (parms[i] == '%')
		{
			convert_fonctions(p_arg, parms[i + 1], result);
			i++;
		}
		else
			forma_my_char(parms[i], result);
		i++;
	}
	va_end(p_arg);
	return (*result);
}

void	convert_fonctions(va_list p_arg, char forma, int *res)
{
	if (forma == 'c')
		forma_my_char(va_arg(p_arg, int), res);
	else if (forma == 's')
		forma_my_putstr(va_arg(p_arg, char *), res);
	else if (forma == 'p')
	{
		forma_my_putstr("0x", res);
		forma_my_nbrbase(va_arg(p_arg, unsigned long), "0123456789abcdef", res);
	}
	else if (forma == 'd' || forma == 'i')
		forma_my_nbr(va_arg(p_arg, int), res);
	else if (forma == 'u')
		forma_my_nbr_ten(va_arg(p_arg, unsigned int), res);
	else if (forma == 'x')
		ft_argputnbr_base(va_arg(p_arg, unsigned int), 0, res);
	else if (forma == 'X')
		ft_argputnbr_base(va_arg(p_arg, unsigned int), 1, res);
	else if (forma == '%')
		forma_my_char('%', res);
}
