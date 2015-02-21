/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 23:47:19 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_print_pointer(t_param *param, int *total_char, va_list *l)
{
	char				*adress;
	unsigned long int	pointer;
	int					i;
	int					left_padding;

	pointer = (unsigned long int)va_arg(l, void *);
	adress = ft_strnew(18);
	left_padding = 0;
	if (adress)
	{
		i = 1;
		adress[0] = '0';
		adress[1] = 'x';
		while ((unsigned int)(pointer >> 60) == 0 && left_padding++ >= 0)
			pointer = pointer << 4;
		while (i < (16 + 1 - left_padding) && i++)
		{
			adress[i] = ft_printf_int_to_hex((unsigned int)(pointer >> 60));
			pointer = pointer << 4;
		}
		*total_char += 16 + 2 - left_padding;
		ft_putstr(adress);
		ft_strdel(&adress);
	}
	(void)param;
}

void	ft_printf_print_octal(t_param *param, int *total_char, va_list *l)
{
	unsigned int	value;
	char			*str;
	int				i;

	value = (int)va_arg(l,unsigned int);
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
		while (str[i] == '0')
			i++;
		ft_memmove(str, str + i, ft_strlen(str) - i);
		str[(11) - i] = '\0';
		str[1] = (str[0] == '\0') ? '\0' : str[1];
		str[0] = (str[0] == '\0') ? '0' : str[0];
		ft_putstr(str);
		ft_strdel(&str);
	}
	(void)param;
	(void)str;
	(void)total_char;
}

void	ft_printf_print_hex_int(t_param *param, int *total_char, va_list *l)
{
	char			*str;
	int				n;
	unsigned int	i;
	int				j;

	str = ft_strnew(4);
	if (str)
	{
		i = 0;
		j = -1;
		n = va_arg(l, int);
		while (!(n >> 28) && i++ < 8)
			n = n << 4;	
		while (i < 8 && (++j) < 8)
		{
			str[j] = ft_printf_int_to_hex((unsigned int)n >> 28);
			if (*(param->specifier) == 'X' && ft_isalpha(str[j]))
				str[j] -= 32;
			i++;
			n = n << 4;
		}
		*total_char += ft_strlen(str);
		ft_putstr(str);
		ft_strdel(&str);
	}
	(void)param;
}