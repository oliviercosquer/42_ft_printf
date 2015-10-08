/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 12:13:51 by olivier           #+#    #+#             */
/*   Updated: 2015/10/08 19:02:15 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_convert.h>

char	*ft_printf_convert_string(va_list *list)
{
	char	*tmp;
	char	*str;

	str = NULL;
	tmp = (char *)va_arg(*list, char *);
	if (tmp)
		str = ft_strdup(tmp);
	return (str);
}