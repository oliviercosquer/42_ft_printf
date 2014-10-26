/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:14:14 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_string(char **s, t_param *param)
{
	int		pos_percent;
	char	*str;
	char	nb_char;
	int		len;

	pos_percent = 0;
	str = *s;
	len = ft_printf_strlen(str);
	nb_char = 0;
	while (str[pos_percent] && str[pos_percent] != '%')
		pos_percent++;
	write(1, str, pos_percent);
	str += pos_percent + ft_printf_get_format_length(param) + 1;
	(void)len;
	*s = str;
	nb_char += ft_printf_padding(param) + pos_percent;
	nb_char += ft_printf_strlen(param->value);
	return (nb_char);
}

int		ft_printf_padding(t_param *param)
{
	int		width;
	int		len_value;
	int		nb_char;

	width = ft_printf_atoi(param->width);
	len_value = ft_printf_strlen(param->value);
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

char	*ft_printf_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	len = ft_printf_strlen(s1) + ft_printf_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	if (str)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			str[i + j] = s2[j];
			j++;
		}
		str[len] = '\0';
	}
	return (str);
}
