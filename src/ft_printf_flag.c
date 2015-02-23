/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 22:40:02 by olivier           #+#    #+#             */
/*   Updated: 2015/02/20 22:51:23 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_flag_numeric_minus(char *str, int len)
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

char	*ft_printf_flag_numeric_plus(char *str)
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

char	*ft_printf_flag_space(char *str, int len)
{
	char	c;
	char	*new_str;

	new_str = str;
	c = ' ';
	len = (len <= 0) ? 1 : len;
	if (str[0] != '-')
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

char	*ft_printf_flag_numeric_0(char *str, int len)
{
	char	c;
	char	*new_str;
	char	len2;

	new_str = str;
	c = '0';
	len2 = (len <= 0) ? 0 : len;
	if (len2)
		new_str = ft_strnew(len2 + ft_strlen(str));
	if (new_str && len2)
	{
		if (str[0] == '-' || str[0] == '+')
		{
			new_str[0] = str[0];
			ft_memset(new_str + 1, c, len2);
			ft_memcpy(new_str + len2 + 1, str + 1, ft_strlen(str + 1) + 1);
		}
		else
		{
			ft_memset(new_str, c, len2);
			ft_memcpy(new_str + len2, str, ft_strlen(str) + 1);
		}
	}
	return (new_str);
}

int		ft_printf_flag_numeric(t_param *param, char *str)
{
	int		width;
	int		len_value;
	char	*new_str;
	char	*tmp;

	width = ft_printf_atoi(param->width);
	len_value = ft_strlen(str);
	new_str = str;
	if (ft_strchr(param->flag, '+'))
		new_str = ft_printf_flag_numeric_plus(str);
	if (ft_strchr(param->flag, '-') && width > len_value)
	{
		tmp = new_str;
		new_str = ft_printf_flag_numeric_minus(new_str, width - len_value);
		if (tmp != new_str && tmp != str)
			ft_strdel(&tmp);
	}
	else if (ft_strchr(param->flag, '0'))
	{
		tmp = new_str;
		new_str = ft_printf_flag_numeric_0(new_str, width - len_value);
		if (tmp != new_str && tmp != str)
			ft_strdel(&tmp);
	}
	else if (ft_strchr(param->flag, ' ') || (param->width && (width - len_value) > 0))
	{
		tmp = new_str;
		new_str = ft_printf_flag_space(new_str, width - len_value);
		if (tmp != new_str && tmp != str)
			ft_strdel(&tmp);
	}
	ft_putstr(new_str);
	return (ft_strlen(new_str) - ft_strlen(str));
}

int		ft_printf_flag_string(t_param *param, char *str)
{
	int		width;
	int		len_value;
	char	*new_str;
	char	*tmp;

	width = ft_printf_atoi(param->width);
	len_value = ft_strlen(str);
	new_str = str;
	if (ft_strchr(param->flag, '-') && width > len_value)
	{
		tmp = new_str;
		new_str = ft_printf_flag_numeric_minus(new_str, width - len_value);
		if (tmp != new_str && tmp != str)
			ft_strdel(&tmp);
	}
	else if ((param->width && (width - len_value) > 0))
	{
		tmp = new_str;
		new_str = ft_printf_flag_space(new_str, width - len_value);
		if (tmp != new_str && tmp != str)
			ft_strdel(&tmp);
	}
	//ft_putstr(new_str);
	return (ft_strlen(new_str));
}
