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
	new_str = NULL;
	pad = ft_strnew(len);
	if (pad)
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
	SEGV
	if (str[0] != '-')
	{
		new_str = ft_strnew(ft_strlen(str) + 1);
		new_str[0] = '+';
		ft_memcpy(new_str + 1, str, ft_strlen(str));
	}
	return (new_str);
}

char	*ft_printf_flag_numeric_space_0(char *flags, char *str)
{
	char	c;
	char	*new_str;

	new_str = NULL;
	if (ft_strchr(flags, '0'))
		c = '0';
	if (ft_strchr(flags, ' '))
		c = ' ';
	new_str = ft_strnew(ft_strlen(str) + 1);
	if (new_str)
	{
		new_str[0] = c;
		ft_memcpy(new_str + 1, str, ft_strlen(str));
	}
	return (new_str);
}

void	ft_printf_flag_numeric(t_param *param, int *total_char, char *str)
{
	int		width;
	int		len_value;
	char	*new_str;

	width = ft_printf_atoi(param->width);
	len_value = ft_strlen(str);
	new_str = NULL;
	if ((len_value - width) > 0 && param->flag)
	{
		if (ft_strchr(param->flag, '+'))
			new_str = ft_printf_flag_numeric_plus(str);
		if (ft_strchr(param->flag, '-'))
		{
			if (new_str)
				new_str = ft_printf_flag_numeric_minus(new_str, len_value - width);
			else
				new_str = ft_printf_flag_numeric_minus(str, len_value - width);
		}
		else if (ft_strchr(param->flag, '0') || ft_strchr(param->flag,' '))
		{
			if (new_str)
				new_str = ft_printf_flag_numeric_space_0(param->flag, new_str);
			else
				new_str = ft_printf_flag_numeric_space_0(param->flag, str);
		}
		if (new_str)
			*total_char += ft_strlen(new_str) - ft_strlen(str);
	}
	else
		new_str = str;
	ft_putstr(new_str);
}

void	ft_printf_flag_string(t_param *param, int *total_char, char *str)
{
	(void)param;
	(void)total_char;
	(void)str;
}
