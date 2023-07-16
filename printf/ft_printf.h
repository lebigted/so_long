/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:10:44 by ltestard          #+#    #+#             */
/*   Updated: 2023/07/15 15:36:11 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *parms, ...);
// void	ft_strlen(char *str);
void	ft_argputnbr_base(unsigned int n, int d, int *res);
void	forma_my_putstr(char *str, int *res);
void	forma_my_nbr( int nb, int *res);
void	forma_my_char(int c, int *res);
void	convert_fonctions(va_list p_arg, char forma, int *res);
void	forma_my_nbrbase(unsigned long nb, char *base, int *res);
void	forma_my_nbr_ten(unsigned int nb, int *res);

#endif
