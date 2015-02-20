/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/20 05:41:04 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_param	*ft_printf_new_param(void)
{
	t_param	*params;

	params = (t_param *)malloc(sizeof(t_param));
	if (params)
	{
		params->flag = '\0';
		params->width = NULL;
		params->precision = NULL;
		params->next = NULL;
		params->specifier = NULL;
		params->specifier_length = NULL;
		params->value = NULL;
		return (params);
	}
	return (NULL);
}

void	ft_printf_add_param(t_param *first, t_param *new_param)
{
	if (first)
	{
		while (first->next)
			first = first->next;
		first->next = new_param;
	}
}

t_param	*ft_printf_get_next_param(char **str)
{
	char	*tmp;
	t_param	*param;

	tmp = *str;
	param = ft_printf_new_param();
	if (param)
	{
		if (ft_has_flag(tmp))
			param->flag = ft_get_flag(tmp);
		if (ft_has_width(tmp))
			param->width = ft_get_width(&tmp);
		if (ft_has_precision(tmp))
			param->precision = ft_get_precision(&tmp);
		param->specifier = ft_get_specifier(&tmp, param);
	}
	return (param);
}

void	ft_printf_del_params(t_param **params)
{
	t_param	*tmp;

	tmp = *params;
	if (tmp->value)
		free(tmp->value);
	if (tmp->width)
		free(tmp->width);
	if (tmp->precision)
		free(tmp->precision);
	if (tmp->specifier)
		free(tmp->specifier);
	if (tmp->specifier_length)
		free(tmp->specifier_length);
	*params = tmp->next;
	free(tmp);
	*params = NULL;
}

t_param	*ft_printf_get_params(char *str, int *total_char)
{
	t_param	*param;
	int		format_length;
	param = NULL;

	if (ft_strchr(VALID_SPECIFIER, *str))
	{
		param = ft_printf_get_next_param(&str);
		format_length = ft_printf_get_format_length(param);
		//str += format_length;
		*total_char += format_length;
	}
	return (param);
}