/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/20 07:52:26 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_param	*ft_printf_new_param(void)
{
	t_param	*params;

	params = (t_param *)malloc(sizeof(t_param));
	if (params)
	{
		params->flag = NULL;
		params->width = NULL;
		params->precision = NULL;
		params->specifier = '\0';
		params->specifier_length = NULL;
		params->value = NULL;
		return (params);
	}
	return (NULL);
}
/*
t_param	*ft_printf_get_next_param(char *str)
{
	char	*tmp;
	t_param	*param;

	tmp = str;
	param = ft_printf_new_param();
	if (param)
	{
		if (ft_has_flag(tmp))
			param->flag = ft_get_flag(tmp);
		if (ft_has_width(tmp))
			param->width = ft_get_width(&tmp);
		if (ft_has_precision(tmp))
			param->precision = ft_get_precision(&tmp);
		//param->specifier = ft_get_specifier(&tmp, param);
	}
	return (param);
}*/

void	ft_printf_del_params(t_param **params)
{
	t_param	*tmp;

	tmp = *params;
	if (tmp)
	{
		if (tmp->value)
			free(tmp->value);
		if (tmp->width)
			free(tmp->width);
		if (tmp->precision)
			free(tmp->precision);
		if (tmp->specifier_length)
			free(tmp->specifier_length);
		free(tmp);
		*params = NULL;
	}
}

void	ft_printf_param_find(char **str, int *total_char)
{
	char	*s;
	int		len;

	len = 0;
	s = *str;
	if (s[len] == '%' && !s[len + 1])
	{
		*str += 1;
	}
	else
	{
		while (s[len] && s[len] != '%')
			len++;
		*total_char += len;
		write(1, s, len);
		*str += len + 1;
	}
}

t_param	*ft_printf_param_parse(char **str, va_list *list)
{
	int		format_length;
	char	*start_str;
	t_param	*param;

	param = NULL;
	format_length = 0;
	if (str && *str)
	{
		start_str = *str;
		param = ft_printf_new_param();
		if (param)
		{
			param->flag = ft_printf_param_parse_flag(str);//DONE
			param->width = ft_printf_param_parse_width(str, list);//DONE
			param->precision = ft_printf_param_parse_precision(str, list);//DONE
			param->specifier_length = ft_printf_param_parse_specifier_length(str);//DONE
			param->specifier = ft_printf_param_parse_specifier(str);//DONE
			format_length = *str - start_str;
		}
	}
	else if (**str)
		*str += 1;
	*str += format_length;
	return (param);
}

t_param	*ft_printf_get_params(char **str, int *total_char, va_list *list)
{
	ft_printf_param_find(str, total_char);
	if (str && *str && **str)
		return (ft_printf_param_parse(str, list));
	return (NULL);
}
