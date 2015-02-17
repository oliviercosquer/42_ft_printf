/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_get2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:01:57 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	ft_get_flag(char *str)
{
	char	flag;

	flag = '\0';
	str++;
	if (ft_strchr(VALID_FLAGS, *str))
		flag = *str;
	return (flag);
}

char	*ft_get_width(char **str)
{
	char	*tmp;
	char	*width;
	int		len;

	len = 0;
	tmp = *str + 1;
	width = NULL;
	tmp += ft_has_flag(*str);
	len = ft_has_width(*str);
	if (len)
		width = ft_strsub(tmp, 0, len);
	return (width);
}

char	*ft_get_precision(char **str)
{
	char	*tmp;
	int		len;
	char	*precision;

	len = 0;
	precision = NULL;
	tmp = *str + 1;
	tmp += ft_has_flag(*str);
	tmp += ft_has_width(*str);
	if (*tmp == '.')
	{
		tmp++;
		if (*tmp == '*')
			len = 1;
		else
			while (ft_isdigit(tmp[len]))
				len++;
		precision = ft_strsub(tmp, 0, len);
	}
	return (precision);
}

char	*ft_get_specifier(char **str, t_param *param)
{
	char	*tmp;
	char	*specifier;
	int		len;

	len = 0;
	tmp = *str + 1;
	specifier = NULL;
	tmp += ft_has_flag(*str);
	tmp += ft_has_width(*str);
	tmp += ft_has_precision(*str);
	while (ft_strchr(VALID_LENGTH, tmp[len]))
		len++;
	if (len)
		param->specifier_length = ft_strsub(tmp, 0, len);
	tmp += len;
	len = 0;
	if (ft_strchr(VALID_SPECIFIER, tmp[len]))
	{
		len++;
		specifier = ft_strsub(tmp, 0, len);
	}
	return (specifier);
}
