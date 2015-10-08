/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 11:37:06 by olivier           #+#    #+#             */
/*   Updated: 2015/10/08 14:33:20 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONVERT_H
# define FT_PRINTF_CONVERT_H
# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>

#include <stdio.h> //TO DELETE

char	*ft_printf_convert_short_integer(va_list *list);
char	*ft_printf_convert_integer(va_list *list);
char	*ft_printf_convert_long_integer(va_list *list);
char	*ft_printf_convert_long_long_integer(va_list *list);

char	*ft_printf_convert_short_unsigned_integer(va_list *list);
char	*ft_printf_convert_unsigned_integer(va_list *list);
char	*ft_printf_convert_long_unsigned_integer(va_list *list);
char	*ft_printf_convert_long_long_unsigned_integer(va_list *list);

char	*ft_printf_convert_octal(va_list *list);
char	*ft_printf_convert_long_octal(va_list *list);
char	*ft_printf_convert_long_long_octal(va_list *list);

char	*ft_printf_convert_double(va_list *list);
char	*ft_printf_convert_long_double(va_list *list);

char	*ft_printf_convert_hex(va_list *list);
char	*ft_printf_convert_long_hex(va_list *list);
char	*ft_printf_convert_long_long_hex(va_list *list);
char	*ft_printf_convert_short_hex(va_list *list);

char	*ft_printf_convert_string(va_list *list);

#endif