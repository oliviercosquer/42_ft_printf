/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:09:33 by ocosquer         ###   ########.fr       */
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

t_param	*ft_printf_get_params(char *str)
{
	t_param	*first;
	t_param	*tmp;

	first = NULL;
	tmp = NULL;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			if (first)
			{
				tmp = ft_printf_get_next_param(&str);
				ft_printf_add_param(first, tmp);
			}
			else
				first = ft_printf_get_next_param(&str);
			str++;
		}
		else if (*(str + 1) == '%' && *str == '%')
			str += 2;
		else
			str += 1;
	}
	return (first);
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
}