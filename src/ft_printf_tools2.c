/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/27 13:17:39 by olivier          ###   ########.fr       */
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

int		ft_printf_strequ(char *s1, char *s2)
{
	int	equal;
	unsigned char	a;
	unsigned char	b;

	equal = 1;
	while (*s1 && *s2 && *s1 == *s2)
	{

	}
	a = (unsigned char)*s1;
	b = (unsigned char)*s2;
	equal = (a - b) == 0 ? 1 : 0;
	return (equal);
}
