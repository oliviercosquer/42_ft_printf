/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:14:21 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_printf_itoa(int n)
{
	char	*nbr;
	int		len;
	int		rest;
	int		negative;

	negative = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	len = ft_printf_getintlength(n) + negative;
	nbr = (char *)malloc(sizeof(char) * len + 1);
	if (nbr)
	{
		nbr[len] = '\0';
		while (len >= 0)
		{
			rest = n % 10;
			nbr[len] = '0' + rest;
			n = n / 10;
			len--;
		}
		if (negative)
			nbr[0] = '-';
	}
	return (nbr);
}

int		ft_printf_getintlength(int n)
{
	int		len;
	int		tmp;

	len = 0;
	tmp = n;
	if (n < 0)
		len = 1;
	while (tmp >= 10)
	{
		len++;
		if (tmp >= 10)
			tmp = tmp / 10;
		else
			tmp = -1;
	}
	return (len);
}

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
			len += ft_printf_strlen(param->width);
	}
	if (param->specifier)
		len++;
	if (param->specifier_length)
		len += ft_printf_strlen(param->specifier_length);
	return (len);
}
