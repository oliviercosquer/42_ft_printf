/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 05:28:08 by ocosquer          #+#    #+#             */
/*   Updated: 2015/10/01 16:47:41 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_print_hex_default(va_list *l)
{
	char			*str;
	unsigned int	n;
	int				i;

	str = ft_strnew(8);
	if (str)
	{
		i = 8;
		n = va_arg(*l, int);
		while (--i >= 0)
		{
			str[i] = ft_printf_int_to_hex(((n << 28) >> 28));
			n = n >> 4;
		}
		i = 0;
		while (str[i] == '0' && i < 7)
			i++;
		ft_memmove(str, str + i, ft_strlen(str + i));
		str[ft_strlen(str + i)] = '\0';
	}
	return (str);
}

char	*ft_printf_print_long_hex(va_list *l)
{
	char				*str;
	unsigned long int	n;
	int					i;

	str = ft_strnew(16);
	if (str)
	{
		i = 16;
		n = va_arg(*l, unsigned long int);
		while (--i >= 0)
		{
			str[i] = ft_printf_int_to_hex(((n << 60) >> 60));
			n = n >> 4;
		}
		i = 0;
		while (str[i] == '0' && i < 15)
			i++;
		ft_memmove(str, str + i, ft_strlen(str + i));
		str[ft_strlen(str + i)] = '\0';
	}
	return (str);
}

char	*ft_printf_print_long_long_hex(va_list *l)
{
	char					*str;
	unsigned long long int	n;
	int				i;

	str = ft_strnew(16);
	if (str)
	{
		i = 16;
		n = va_arg(*l, unsigned long long int);
		while (--i >= 0)
		{
			str[i] = ft_printf_int_to_hex(((n << 60) >> 60));
			n = n >> 4;
		}
		i = 0;
		while (str[i] == '0' && i < 15)
			i++;
		ft_memmove(str, str + i, ft_strlen(str + i));
		str[ft_strlen(str + i)] = '\0';
	}
	return (str);
}

char	*ft_printf_print_short_hex(va_list *l)
{
	char			*str;
	unsigned int	n;
	int				i;

//	ft_putstr("SEGV\n");
	str = ft_strnew(8);
	if (str)
	{
		i = 8;
		n = va_arg(*l, int);
		while (--i >= 0)
		{
			str[i] = ft_printf_int_to_hex(((n << 28) >> 28));
			n = n >> 4;
		}
		i = 0;
		while (str[i] == '0' && i < 7)
			i++;
		ft_memmove(str, str + i, ft_strlen(str + i));
		str[ft_strlen(str + i)] = '\0';
	}
	return (str);
}
