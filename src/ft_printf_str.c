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
