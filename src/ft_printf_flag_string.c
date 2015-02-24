/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:04:19 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/24 14:04:25 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
		new_str = ft_printf_flag_integer_minus(new_str, width - len_value);
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
	ft_putstr(new_str);
	return (ft_strlen(new_str));
}