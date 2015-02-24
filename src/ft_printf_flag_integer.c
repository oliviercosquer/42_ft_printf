/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:00:39 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/24 14:00:51 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_flag_integer_minus(char *str, int len)
{
	char	c;
	char	*new_str;
	char	*pad;

	c = ' ';
	new_str = str;
	if (len)
		pad = ft_strnew(len);
	if (pad && len)
	{
		ft_memset(pad, c, len);
		new_str = ft_strjoin(str, pad);
		ft_strdel(&pad);
	}
	return (new_str);
}

char	*ft_printf_flag_integer_plus(char *str)
{
	char	*new_str;

	new_str = str;
	if (str[0] != '-')
	{
		new_str = ft_strnew(ft_strlen(str) + 1);
		if (new_str)
		{
			new_str[0] = '+';
			ft_memcpy(new_str + 1, str, ft_strlen(str));
		}
	}
	return (new_str);
}

char	*ft_printf_flag_integer_0(char *str, int len)
{
	char	c;
	char	*new_str;
	char	min_len;

	new_str = str;
	c = '0';
	if ((str[0] == '-' || str[0] == '+'))
		min_len = len - (ft_strlen(str) - 1);
	else		
		min_len = len;
	min_len = (len <= 0) ? 0 : min_len;
	if (min_len)
	{
		new_str = ft_strnew(min_len + ft_strlen(str));
		if ((str[0] == '-' || str[0] == '+'))
		{
			new_str[0] = str[0];
			ft_memset(new_str + 1, c, min_len);
			ft_memcpy(new_str + min_len + 1, str + 1, ft_strlen(str + 1) + 1);
		}
		else
		{
			ft_memset(new_str, c, min_len);
			ft_memcpy(new_str + min_len, str, ft_strlen(str));
		}
	}
	return (new_str);
}

int		ft_printf_flag_integer(t_param *param, char *str)
{/*
	int		width;
	int		len_value;
	char	*new_str;
	char	*tmp;

	width = ft_printf_atoi(param->width);
	len_value = ft_strlen(str);
	new_str = str;
	if (ft_strchr(param->flag, '+'))
		new_str = ft_printf_flag_integer_plus(str);
	if (ft_strchr(param->flag, '-') && width > len_value)
	{
		tmp = new_str;
		new_str = ft_printf_flag_integer_minus(new_str, width - len_value);
		if (tmp != new_str && tmp != str)
			ft_strdel(&tmp);
	}
	else if (ft_strchr(param->flag, '0') || param->precision)
	{
		tmp = new_str;
		if (param->precision)
			width = ft_printf_atoi(param->precision);
		new_str = ft_printf_flag_integer_0(new_str, width - len_value);
		if (tmp != new_str && tmp != str)
			ft_strdel(&tmp);
	}
	if (!param->precision)
	{
		if (ft_strchr(param->flag, ' ') || (param->width && (width - len_value) > 0))
		{
			width = ft_printf_atoi(param->width);
			tmp = new_str;
			new_str = ft_printf_flag_space(new_str, width - ft_strlen(new_str));
			if (tmp != new_str && tmp != str)
				ft_strdel(&tmp);
		}
	}*/
		(void)param;
	if (str)
		ft_putstr(str);
	return (ft_strlen(str));
}