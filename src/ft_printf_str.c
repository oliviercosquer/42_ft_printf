/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/20 08:54:38 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_padding(t_param *param)
{
	int		width;
	int		len_value;
	int		nb_char;

	width = ft_printf_atoi(param->width);
	len_value = ft_strlen(param->value);
	if (param->flag == 'c')
		len_value = 1;
	nb_char = 0;
	if (param->flag == '-')
	{
		write(1, param->value, len_value);
		while (width > len_value)
		{
			write(1, " ", 1);
			width--;
			nb_char++;
		}
	}
	else
	{
		while (width > len_value)
		{
			if (param->flag == '0')
				write(1, &param->flag, 1);
			else
				write(1, " ", 1);
			width--;
			nb_char++;
		}
		write(1, param->value, len_value);
	}
	return (nb_char);
}
