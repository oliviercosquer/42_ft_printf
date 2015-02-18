/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 23:33:36 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/17 23:33:38 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char	*ft_printf_get_float_simple(double f)
{
	double	n;
	int		i;
	char	*str;
	char	*tmp;
	char	*tmp2;

	n = (double)f;
	i = (int)n;	
	str = ft_itoa((int)n);
	tmp = str;
	str = ft_strjoin(str, ".");
	ft_strdel(&tmp);
	tmp = ft_itoa((n - i) * 1000000);
	tmp2 = str;
	str = ft_strjoin(str, tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (str);
}
/*
static	char	*ft_printf_get_float_double(double d)
{

}*/

char	*ft_printf_get_float(va_list *l, t_param *param)
{
	char	*specifier;

	specifier = param->specifier;
	(void)specifier;
	return (ft_printf_get_float_simple(va_arg(*l, double)));
}