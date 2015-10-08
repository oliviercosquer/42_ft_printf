/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 13:13:53 by olivier           #+#    #+#             */
/*   Updated: 2015/10/08 14:20:14 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_param.h>

t_param	*ft_printf_param_new(void)
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

void	ft_printf_params_del(t_param **params)
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