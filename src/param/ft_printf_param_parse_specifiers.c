/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_param_parse_specifiers.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 13:16:02 by olivier           #+#    #+#             */
/*   Updated: 2015/10/08 14:27:55 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_param.h>

char	*ft_printf_param_parse_flag(char **str)
{
	int		len;
	char	*s;
	char	*flag;

	len = 0;
	flag = NULL;
	if (str && *str)
	{
		s = *str;
		while (s[len] && ft_strchr(VALID_FLAGS, s[len]))
			len++;
		if (len)
			flag = ft_strsub(s, 0, len);
		*str += len;
	}
	return (flag);
}

char	*ft_printf_param_parse_width(char **str, va_list *list)
{
	int		len;
	char	*s;
	char	*width;

	len = 0;
	width = NULL;
	if (str && *str)
	{
		s = *str;
		if (**str == '*')
		{
			width = ft_itoa(va_arg(*list, int));
			len++;
		}
		else
		{
			while (s[len] && ft_isdigit(s[len]))
				len++;
			if (len)
				width = ft_strsub(s, 0, len);
		}
		*str += len;
	}
	return (width);
}

char	*ft_printf_param_parse_precision(char **str, va_list *list)
{
	int		len;
	char	*s;
	char	*precision;

	len = 0;
	precision = NULL;
	if (str && *str && **str == '.')
	{
		s = *str + 1;
		if (*s == '*')
		{
			precision = ft_itoa(va_arg(*list, int));
			len++;
		}
		else
		{
			while (s[len] && ft_isdigit(s[len]))
				len ++;
			precision = ft_strsub(s, 0, len);			
		}
		*str += len + 1;
	}
	return (precision);
}

char	*ft_printf_param_parse_specifier_length(char **str)
{
	int		len;
	char	*s;
	char	*specifier_length;

	len = 0;
	specifier_length = NULL;
	if (str && *str)
	{
		s = *str;
		while (s[len] && ft_strchr(VALID_LENGTH, s[len]))
			len++;
		if (len)
			specifier_length = ft_strsub(s, 0, len);
		*str += len;
	}
	return (specifier_length);
}

char	ft_printf_param_parse_specifier(char **str)
{
	char	specifier;

	specifier = '\0';
	if (str && *str)
	{
		specifier = **str;
		if (ft_strchr(VALID_SPECIFIER, **str))
		{
			*str += 1;
		}
	}
	return (specifier);
}
