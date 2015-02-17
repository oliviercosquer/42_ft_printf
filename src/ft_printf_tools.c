/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/04 02:39:43 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_get_format_length(t_param *param)
{
	int	len;

	len = 0;
	if (param->flag)
		len++;
	if (param->width)
	{
		if (*(param->width) == '*')
			len++;
		else
			len += ft_strlen(param->width);
	}
	if (param->specifier)
		len++;
	if (param->specifier_length)
		len += ft_strlen(param->specifier_length);
	return (len);
}

int		ft_printf_atoi(const char *str)
{
	int	value;

	value = 0;
	while (str && *str)
	{
		value = (value * 10) + (*str - '0');
		str++;
	}
	return (value);
}