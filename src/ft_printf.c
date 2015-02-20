/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/20 08:28:06 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_display_param(t_param *param)
{
	if (param)
	{
		printf("Flag:%c, Width:%s, Precision:%s, Specifier:%s, Length:%s\n",
			param->flag, param->width, param->precision, param->specifier,
			param->specifier_length);
	}
}

int		ft_printf(const char *s, ...)
{
	va_list	list;
	t_param	*param;
	char	*str;
	int		total_char;

	va_start(list, s);
	str = (char *)s;
	total_char = 0;
	while ((param = ft_printf_get_params(&str, &total_char)))
	{
		// ft_display_param(param);
		ft_printf_call(param, &total_char, &list);
		ft_printf_del_params(&param);
	}
	write(1, str, ft_strlen(str));
	return (total_char);
	va_end(list);
}