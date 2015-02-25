/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/23 07:33:42 by olivier          ###   ########.fr       */
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

void	ft_printf_del_params(t_param **params)
{
	t_param	*tmp;

	tmp = *params;
	if (tmp)
	{
		if (tmp->flag)
			free(tmp->flag);
		if (tmp->width)
			free(tmp->width);
		if (tmp->precision)
			free(tmp->precision);
		if (tmp->specifier_length)
			free(tmp->specifier_length);
		if (tmp->value)
			free(tmp->value);
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
	if (s[len])
	{
		if (s[len] == '%' && !s[len + 1])
		{
			*str += 1;
		}
		else
		{
			while (s[len] && s[len] != '%')
				len++;
			write(1, s, len);
			*total_char += len;
			*str += len + 1;
		}
	}
}

void	ft_printf_param_special(t_param *param)
{

	if (!param->specifier_length)
		param->specifier_length = ft_strdup("l");
	if (param->specifier == 'D')
		param->specifier = 'd';
	if (param->specifier == 'U')
		param->specifier = 'u';
	if (param->specifier == 'O')
		param->specifier = 'o';
}

t_param	*ft_printf_param_parse(char **str, va_list *list)
{
	t_param	*param;

	param = NULL;
	if (str && *str)
	{
		param = ft_printf_new_param();
		if (param)
		{
			param->flag = ft_printf_param_parse_flag(str);//DONE
			param->width = ft_printf_param_parse_width(str, list);//DONE
			param->precision = ft_printf_param_parse_precision(str, list);//DONE
			param->specifier_length = ft_printf_param_parse_specifier_length(str);//DONE
			param->specifier = ft_printf_param_parse_specifier(str);//DONE
			if (ft_strchr(SPECIAL_SPECIFIER, param->specifier))
				ft_printf_param_special(param);
		}
	}
	else if (**str)
		*str += 1;
	return (param);
}

t_param	*ft_printf_get_params(char **str, int *total_char, va_list *list)
{
	ft_printf_param_find(str, total_char);
	if (str && *str && **str)
		return (ft_printf_param_parse(str, list));
	return (NULL);
}
