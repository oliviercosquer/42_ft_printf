/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 22:40:02 by olivier           #+#    #+#             */
/*   Updated: 2015/02/24 07:46:26 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_flag_void(t_param *param, char *str)
{
	(void)param;
	(void)str;
	return (0);
}

t_flag_func	ft_printf_get_flag_func(char specifier)
{
	static t_flag_func	functions[256];
	t_flag_func			func;

	func = NULL;
	if (!functions['d'])
	{
		functions['d'] = &ft_printf_flag_integer;
		functions['i'] = &ft_printf_flag_integer;
		functions['o'] = &ft_printf_flag_string;
		functions['O'] = &ft_printf_flag_string;
		functions['u'] = &ft_printf_flag_integer;
		functions['x'] = &ft_printf_flag_string;
		functions['X'] = &ft_printf_flag_string;
		//functions['s'] = &ft_printf_flag_string;
		//functions['c'] = &ft_printf_flag_c;
	}
	func = functions[(int)specifier];
	if (func)
		return (func);
	else
		return (&ft_printf_flag_void);
}

char	*ft_printf_flag_space(char *str, int len)
{
	char	c;
	char	*new_str;

	new_str = str;
	c = ' ';
	len = (len <= 0) ? 0 : len;
	if (str)
	{
		new_str = ft_strnew(len + ft_strlen(str));
		if (new_str)
		{
			ft_memset(new_str, c, len);
			ft_memcpy(new_str + len, str, ft_strlen(str) + 1);
		}
	}
	return (new_str);
}
