/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_octal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 12:04:38 by olivier           #+#    #+#             */
/*   Updated: 2015/10/08 14:31:22 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_convert.h>

char	*ft_printf_convert_octal(va_list *list)
{
	unsigned int	value;
	char			*str;
	int				i;

	value = (int)va_arg(*list, unsigned int);
	str = ft_strnew(11);
	i = 11;
	if (str)
	{
		while (--i >= 0)
		{
			str[i] = '0' + ((value << 29) >> 29);
			value = value >> 3;
		}
		i = 0;
		while (str[i] == '0' && i < 10)
			i++;
		ft_memmove(str, str + i, ft_strlen(str) - i);
		str[(11) - i] = '\0';
		str[1] = (str[0] == '\0') ? '\0' : str[1];
		str[0] = (str[0] == '\0') ? '0' : str[0];
	}
	return (str);
}

char	*ft_printf_convert_long_octal(va_list *list)
{
	unsigned long int	value;
	char				*str;
	int					i;


	value = (int)va_arg(*list, unsigned long int);
	str = ft_strnew(23);
	i = 22;
	if (str)
	{
		while (--i >= 0)
		{
			str[i] = '0' + (unsigned long int)((value << 61) >> 61);
			value = value >> 3;
		}
		i = 0;
		while (str[i] == '0' && i < 22)
			i++;
		ft_memmove(str, str + i, ft_strlen(str) - i);
		str[(22) - i] = '\0';
		str[1] = (str[0] == '\0') ? '\0' : str[1];
		str[0] = (str[0] == '\0') ? '0' : str[0];
	}
	return (str);
}

char	*ft_printf_convert_long_long_octal(va_list *list)
{
	unsigned long long int	value;
	char					*str;
	int						i;

	value = (int)va_arg(*list, unsigned long long int);
	str = ft_strnew(23);
	i = 22;
	if (str)
	{
		while (--i >= 0)
		{
			str[i] = '0' + ((value << 61) >> 61);
			value = value >> 3;
		}
		i = 0;
		while (str[i] == '0' && i < 22)
			i++;
		ft_memmove(str, str + i, ft_strlen(str) - i);
		str[(22) - i] = '\0';
		str[1] = (str[0] == '\0') ? '\0' : str[1];
		str[0] = (str[0] == '\0') ? '0' : str[0];
	}
	return (str);
}