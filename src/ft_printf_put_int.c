/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:13:15 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_get_signed_int(t_param *param, int n)
{
	char	*nbr;

	nbr = ft_itoa(n);
	if (param->flag == '+')
	{
		if (n >= 0)
			nbr = ft_printf_strjoin("+", nbr);
	}
	if (param->flag == ' ' && n > 0)
		nbr = ft_printf_strjoin(" ", nbr);
	return (nbr);
}

char	*ft_printf_get_unsigned_int(t_param *param, unsigned int n)
{
	char			*nbr;

	if (param->flag == '+')
		write(1, "+", 1);
	if (param->flag == ' ')
		write(1, " ", 1);
	nbr = ft_printf_unsigned_itoa(n);
	return (nbr);
}
