/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 00:12:10 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	ft_printf_int_to_hex(unsigned int i)
{
	if (i <= 9)
		return ('0' + i);
	else
		return ('a' + (i - 10));
}

void	ft_printf_print_pointer(t_param *param, int *total_char, va_list *l)
{
	char				*adress;
	unsigned long int	pointer;
	int					i;
	int					left_padding;

	pointer = (unsigned long int)va_arg(l, void *);
	adress = ft_strnew(18);
	left_padding = 0;
	if (adress)
	{
		i = 1;
		*total_char += 18;
		adress[0] = '0';
		adress[1] = 'x';
		while ((unsigned int)(pointer >> 60) == 0 && left_padding++ >= 0)
			pointer = pointer << 4;
		while (i < (16 + 2 - left_padding) && i++)
		{
			adress[i] = ft_printf_int_to_hex((unsigned int)(pointer >> 60));
			pointer = pointer << 4;
		}
		ft_putstr(adress);
		ft_strdel(&adress);
	}
	(void)param;
}