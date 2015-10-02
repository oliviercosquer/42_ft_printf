/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 05:28:08 by ocosquer          #+#    #+#             */
/*   Updated: 2015/10/02 12:56:12 by olivier          ###   ########.fr       */
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
/*
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
*/
char	*ft_printf_print_short_hex(va_list *l)
{
	char			*str;
	unsigned int	n;

	unsigned int	i;
	unsigned int	r;
	int				j;

//	ft_putstr("SEGV\n");
	r = va_arg(*l, int);
	i = 0;
	j = 8;
	str = ft_strnew(8);

	if (str)
	{
		printf("r: %i; i: %i\n", r, i);
		while ((r / 16) > 16)
		{
			i = r - (r / 16);
			r = r / 16;
			str[j] = ft_printf_int_to_hex(i);
			j--;
			printf("r: %i; i: %i\n", r, i);
		}
		i = r - (r / 16);
		r = r / 16;
		str[j - 1] = ft_printf_int_to_hex(i);
		str[j - 2] = ft_printf_int_to_hex(r);
		j = 0;
		while (str[j] == '0' && j < 7)
			j++;
		ft_memmove(str, str + j, ft_strlen(str + j));
		str[ft_strlen(str + j)] = '\0';
	}
	return (str);
}