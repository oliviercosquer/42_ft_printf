/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/04 02:20:26 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_put(va_list *l, t_param *param)
{
	char	specifier;
	char	*tmp;

	tmp = NULL;
	if (param && param->specifier)
	{
		specifier = *(param->specifier);
		if (specifier == 'd' || specifier == 'i')
			tmp = ft_printf_get_di(l, param);
		if (specifier == 's')
			tmp = ft_printf_get_s(l, param);
		if (specifier == 'c')
			tmp = ft_printf_get_c(l, param);
	}
	return (tmp);
}

char	*ft_printf_get_di(va_list *l, t_param *param)
{
	char	*tmp;

	tmp = NULL;
	if (!param->specifier_length)
	{
		tmp = ft_printf_get_signed_int(param, va_arg(l, int));
	}
	else
	{
		if (ft_printf_strequ(param->specifier_length, "h"))
			tmp = ft_printf_get_signed_int(param, va_arg(l, int));
		if (ft_printf_strequ(param->specifier_length, "l"))
			tmp = ft_printf_get_signed_int(param, va_arg(l,long int));
	}
	return (tmp);
}

char	*ft_printf_get_s(va_list *l, t_param *param)
{
	char	*str;

	str = va_arg(*l, char *);
	(void)param;
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_printf_strdup(str));
}

char	*ft_printf_get_c(va_list *l, t_param *param)
{
	char	c;
	char	*tmp;

	(void)param;
	c = (char)va_arg(*l, int);
	tmp = (char *)malloc(sizeof(char) * 2);
	if (tmp)
	{
		tmp[0] = c;
		tmp[1] = '\0';
	}
	return (tmp);
}
