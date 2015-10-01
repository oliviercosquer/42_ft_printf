/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/10/01 15:22:28 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_print_c(t_param *param, char c)
{
	int				nb_char;
	t_flag_func		func;

	nb_char = 1;
	ft_putchar(c);
	(void)func;
	(void)param;
	return (nb_char);
}

int		ft_printf_print_string_default(t_param *param, char *str)
{
	int				nb_char;
	t_flag_func		func;

	nb_char = ft_strlen(str);
	ft_putstr(str);
	(void)func;
	(void)param;
	/*
	func = ft_printf_get_flag_func(param->specifier);
	if (func)
		nb_char += func(param, str);*/
	return (nb_char);
}

int		ft_printf_print_wchar_c(t_param *param, wchar_t c)
{
	(void)param;
	write(1, &c, sizeof(wchar_t));
	return (1);
}

int		ft_printf_print_wchar_default(t_param *param, wchar_t *str)
{
	int				nb_char;
	//t_flag_func		func;

	(void)param;
	ft_printf_putwstr(str);
	nb_char = ft_printf_wstrlen(str);
	return (nb_char);	
}

int		ft_printf_print_pointer(t_param *param, va_list *l)
{
	char				*str;
	unsigned long int	pointer;
	int					i;
	int					nb_char;

	pointer = (unsigned long int)va_arg(*l, void *);
	str = ft_strnew(19);
	nb_char = 0;
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
		ft_memmove(str + 2, str + i, ft_strlen(str + i));
		str[ft_strlen(str + i) + 2] = '\0';
		nb_char += ft_strlen(str);
		ft_putstr(str);
		ft_strdel(&str);
	}
	(void)param;
	return (nb_char);
}
