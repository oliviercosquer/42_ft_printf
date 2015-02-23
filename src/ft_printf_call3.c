/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 07:07:02 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/22 07:07:10 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_print_u(t_param *param, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func		func;
	unsigned int		modifier;
	char				*str;
	int					nb_char;

	modifier = 0;
	nb_char = 0;
	if (!functions[0])
	{
		functions[0] = &ft_printf_print_long_uinteger;
		functions['l'] = &ft_printf_print_long_uinteger;
	}
	if (param->specifier_length)
	{
		modifier = *(param->specifier_length);
		if (ft_strlen(param->specifier_length) == 2)
			modifier -= 32;
	}
	func = functions[modifier];
	if (func)
	{
		str = func(l);
		nb_char += ft_printf_flag_numeric(param, str);
		ft_strdel(&str);
	}
	return (nb_char);
}