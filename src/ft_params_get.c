/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/04 02:02:48 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_param	*ft_get_params(char *str)
{
	t_param	*first;
	t_param	*tmp;

	first = NULL;
	tmp = NULL;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			if (first)
			{
				tmp = ft_printf_get_next_param(&str);
				ft_printf_add_param(first, tmp);
			}
			else
				first = ft_printf_get_next_param(&str);
			str++;
		}
		else if (*(str + 1) == '%' && *str == '%')
			str += 2;
		else
			str += 1;
	}
	return (first);
}

t_param	*ft_get_next_param(char **str)
{
	char	*tmp;
	t_param	*param;

	tmp = *str;
	param = ft_printf_new_param();
	if (param)
	{
		if (ft_has_flag(tmp))
			param->flag = ft_get_flag(tmp);
		if (ft_has_width(tmp))
			param->width = ft_get_width(&tmp);
		if (ft_has_precision(tmp))
			param->precision = ft_get_precision(&tmp);
		param->specifier = ft_get_specifier(&tmp, param);
	}
	return (param);
}
