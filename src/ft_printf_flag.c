/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 22:40:02 by olivier           #+#    #+#             */
/*   Updated: 2015/02/20 22:51:23 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_flag_numeric(t_param *param, int *total_char, char *str)
{
	int		width;
	int		len_value;
	char	c;

	width = ft_printf_atoi(param->width);
	len_value = ft_strlen(str);
	c = param->flag;
	if (c == '0' || c == ' ')
	{
		while (width > len_value)
		{
			width--;
			*total_char += 1;
			ft_putchar(c);
		}
	}
	if (c == '+')
	{
		if (str[0] != '-')
		{
			ft_putchar('+');
			*total_char += 1;
		}
	}
}

void	ft_printf_flag_string(t_param *param, int *total_char, char *str)
{
	(void)param;
	(void)total_char;
	(void)str;
}