/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_double.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 12:15:05 by olivier           #+#    #+#             */
/*   Updated: 2015/10/05 14:15:58 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_convert.h>

char	*ft_printf_convert_double(va_list *list)
{
	double	n;
	int		i;
	char	*str;
	char	*tmp;
	char	*tmp2;

	n = va_arg(*list, double);
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
	ft_putstr(str);
	return (str);
}

char	*ft_printf_convert_long_double(va_list *list)
{
	//@TODO
	(void)list;
	return (NULL);
}