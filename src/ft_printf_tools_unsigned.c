/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:14:40 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_get_unsigned_intlength(unsigned int n)
{
	int				len;
	unsigned int	tmp;

	len = 0;
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
	unsigned int	len;
	unsigned int	rest;

	len = ft_printf_get_unsigned_intlength(n);
	nbr = (char *)malloc(sizeof(char) * len + 1);
	if (nbr)
	{
		while (len > 0)
		{
			rest = n % 10;
			nbr[len] = '0' + rest;
			n = n / 10;
			len--;
		}
		nbr[len] = '\0';
	}
	return (nbr);
}
