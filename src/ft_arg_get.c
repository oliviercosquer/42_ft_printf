/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/04 01:55:35 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_get_arg(va_list *l, t_param *param)
{
	char	*tmp;

	if (param->width && *(param->width) == '*')
	{
		tmp = ft_itoa(va_arg(*l, int));
		param->width = tmp;
	}
	if (param->precision && *(param->precision) == '*')
	{
		tmp = ft_itoa(va_arg(*l, int));
		param->precision = tmp;
	}
	return (ft_printf_get(l, param));
}
