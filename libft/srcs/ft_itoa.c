/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:31:01 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:54:01 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_getintlength(int n)
{
	int		len;
	int		tmp;
	int		negative;

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

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;
	int		rest;
	int		negative;

	negative = (n < 0) ? -1 : 1;
	len = ft_getintlength(n) + 1;
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
