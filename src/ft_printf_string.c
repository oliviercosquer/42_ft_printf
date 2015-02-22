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
	char				*str;
	unsigned long int	pointer;
	int					i;

	pointer = (unsigned long int)va_arg(l, void *);
	str = ft_strnew(18);
	if (str)
	{
		str[0] = '0';
		str[1] = 'x';
		i = 19;
		while (--i > 1)
		{
			str[i] = ft_printf_int_to_hex((unsigned int)((pointer << 60) >> 60));
			pointer = pointer >> 4;
		}
		i = 2;
		while (str[i] == '0' && i < 18)
			i++;
		//printf("str:%s\ni:%d\n", str, i);
		ft_memmove(str + 2, str + i, ft_strlen(str + i));
		str[ft_strlen(str + i) + 2] = '\0';
		*total_char += ft_strlen(str);
		ft_putstr(str);
		ft_strdel(&str);
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
		*total_char += ft_strlen(str);
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