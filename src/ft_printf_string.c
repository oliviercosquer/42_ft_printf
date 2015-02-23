/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 23:47:19 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_print_pointer(t_param *param, int *total_char, va_list *l)
{
	char				*str;
	unsigned long int	pointer;
	int					i;

	pointer = (unsigned long int)va_arg(l, void *);
	str = ft_strnew(19);
	if (str)
	{
		str[0] = '0';
		str[1] = 'x';
		i = 19;
		while (--i > 1)
		{
			str[i] = ft_printf_int_to_hex((unsigned int)((pointer << 60) >> 60));
			pointer = pointer >> 4;
		}
		i = 2;
		while (str[i] == '0' && i < 18)
			i++;
		ft_memmove(str + 2, str + i, ft_strlen(str + i));
		str[ft_strlen(str + i) + 2] = '\0';
		*total_char += ft_strlen(str);
		ft_putstr(str);
		ft_strdel(&str);
	}
	(void)param;
}
