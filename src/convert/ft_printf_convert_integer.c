/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_integer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 12:05:46 by olivier           #+#    #+#             */
/*   Updated: 2015/10/05 13:42:51 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_convert.h>

char	*ft_printf_convert_short_integer(va_list *list)
{
	short int	n;
	char		*n_str;

	n_str = NULL;
	n = va_arg(*list, short int);
	//@TODO
	(void)n;
	return (n_str);
}

char	*ft_printf_convert_integer(va_list *list)
{
	int		n;
	char	*n_str;

	n_str = NULL;
	n = va_arg(*list, int);
	n_str = ft_itoa(n);
	return (n_str);
}

char	*ft_printf_convert_long_integer(va_list *list)
{
	long int	n;
	char		*n_str;

	n_str = NULL;
	n = va_arg(*list, long int)
	//@TODO
	(void)n;
	return (n_str);
}

char	*ft_printf_convert_long_long_integer(va_list *list)
{
	long long int	n;
	char			*n_str;

	n_str = NULL;
	n = va_arg(*list, long long int)
	//@TODO
	(void)n;
	return (n_str);
}
