/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_signed.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:23:59 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 01:04:49 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_lint_length(long int n)
{
	long int	len;
	long int	tmp;
	int			negative;

	len = 0;
	tmp = n;
	negative = (n < 0) ? -1 : 1;
	while (tmp >= 10 || tmp <= -10)
	{
		len++;
		if (tmp >= 10 || tmp <= -10)
			tmp = (tmp / 10) * negative;
		else
			tmp = -negative;
	}
	return (len);
}

int		ft_printf_long_lint_length(long int n)
{
	long long int	len;
	long long int	tmp;
	int			negative;

	len = 0;
	tmp = n;
	negative = (n < 0) ? -1 : 1;
	while (tmp >= 10 || tmp <= -10)
	{
		len++;
		if (tmp >= 10 || tmp <= -10)
			tmp = (tmp / 10) * negative;
		else
			tmp = -negative;
	}
	return (len);
}

char	*ft_printf_lint_itoa(long int n)
{
	char		*nbr;
	long int	len;
	long int	rest;
	int			negative;

	negative = (n < 0) ? -1 : 1;
	len = ft_printf_lint_length(n) + 1;
	len += (negative == -1) ? 1 : 0;
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (nbr)
	{
		nbr[len] = '\0';
		len--;
		while (len >= 0)
		{
			rest = (n % 10);
			nbr[len] = (negative == -1) ? '0' + (rest * negative) : '0' + rest;
			n = (n / 10);
			len--;
		}
		if (negative == -1)
			nbr[0] = '-';
	}
	return (nbr);
}

char	*ft_printf_long_lint_itoa(long int n)
{
	char			*nbr;
	long long int	len;
	long long int	rest;
	int				negative;

	negative = (n < 0) ? -1 : 1;
	len = ft_printf_long_lint_length(n) + 1;
	len += (negative == -1) ? 1 : 0;
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (nbr)
	{
		nbr[len] = '\0';
		len--;
		while (len >= 0)
		{
			rest = (n % 10);
			nbr[len] = (negative == -1) ? '0' + (rest * negative) : '0' + rest;
			n = (n / 10);
			len--;
		}
		if (negative == -1)
			nbr[0] = '-';
	}
	return (nbr);
}