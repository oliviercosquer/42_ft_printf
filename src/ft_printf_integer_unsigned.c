/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_unsigned.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 01:05:50 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_unsigned_length(unsigned int n)
{
	int				len;
	unsigned int	tmp;

	len = 1;
	tmp = n;
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

int		ft_printf_ulong_length(unsigned long int n)
{
	unsigned long int	len;
	unsigned long int	tmp;

	len = 1;
	tmp = n;
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

char	*ft_printf_unsigned_itoa(unsigned int n)
{
	char			*nbr;
	int				len;
	unsigned int	rest;

	len = ft_printf_unsigned_length(n);
	nbr = (char *)malloc(sizeof(char) * len + 1);
	if (nbr)
	{
		nbr[len] = '\0';
		len--;
		while (len >= 0)
		{
			rest = n % 10;
			nbr[len] = '0' + rest;
			n = n / 10;
			len--;
		}
	}
	return (nbr);
}

char	*ft_printf_ulong_itoa(unsigned long int n)
{
	char				*nbr;
	int					len;
	unsigned long int	rest;

	len = ft_printf_ulong_length(n);
	nbr = (char *)malloc(sizeof(char) * len + 1);
	if (nbr)
	{
		nbr[len] = '\0';
		len--;
		while (len >= 0)
		{
			rest = n % 10;
			nbr[len] = '0' + rest;
			n = n / 10;
			len--;
		}
	}
	return (nbr);
}