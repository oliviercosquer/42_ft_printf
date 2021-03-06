/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 04:34:03 by ocosquer          #+#    #+#             */
/*   Updated: 2015/10/01 15:50:28 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_print_octal_default(va_list *l)
{
	unsigned int	value;
	char			*str;
	int				i;

	value = (int)va_arg(*l, unsigned int);
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

char	*ft_printf_print_long_octal(va_list *l)
{
	unsigned long int	value;
	char				*str;
	int					i;


	value = (int)va_arg(*l, unsigned long int);
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

char	*ft_printf_print_long_long_octal(va_list *l)
{
	unsigned long long int	value;
	char					*str;
	int						i;

	value = (int)va_arg(*l, unsigned long long int);
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
