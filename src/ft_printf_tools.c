/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 03:44:13 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_atoi(const char *str)
{
	int	value;

	value = 0;
	while (str && *str)
	{
		value = (value * 10) + (*str - '0');
		str++;
	}
	return (value);
}

char	ft_printf_int_to_hex(unsigned int i)
{
	if (i <= 9)
		return ('0' + i);
	else
		return ('a' + (i - 10));
}

void	ft_printf_str_toupper(char **str)
{
	char	*s;

	if (str)
	{
		s = *str;
		while (*s)
		{
			*s = ft_toupper(*s);
			s++;
		}
	}
}
