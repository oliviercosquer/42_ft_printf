/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/04 02:29:59 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_putstr(void *s, t_param *param)
{
	char	*str;

	(void)param;
	str = (char *)s;
	if (str)
		write(1, str, ft_strlen(str));
	else
		write(1, MSG_NULL_POINTER, ft_strlen(MSG_NULL_POINTER));
}

int		ft_printf_string(char **s, t_param *param)
{
	int		pos_percent;
	char	*str;
	char	nb_char;

	pos_percent = 0;
	str = *s;
	nb_char = 0;
	while (str[pos_percent] && str[pos_percent] != '%')
		pos_percent++;
	write(1, str, pos_percent);
	*s += pos_percent + ft_printf_get_format_length(param) + 1;
	nb_char += ft_printf_padding(param) + pos_percent;
	nb_char += ft_strlen(param->value);
	return (nb_char);
}

int		ft_printf_padding(t_param *param)
{
	int		width;
	int		len_value;
	int		nb_char;

	width = ft_printf_atoi(param->width);
	len_value = ft_strlen(param->value);
	nb_char = 0;
	if (param->flag == '-')
	{
		write(1, param->value, len_value);
		while (width > len_value)
		{
			write(1, " ", 1);
			width--;
			nb_char++;
		}
	}
	else
	{
		while (width > len_value)
		{
			if (param->flag == '0')
				write(1, &param->flag, 1);
			else
				write(1, " ", 1);
			width--;
			nb_char++;
		}
		write(1, param->value, len_value);
	}
	return (nb_char);
}
