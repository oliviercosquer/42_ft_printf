/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/10/08 14:45:08 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MSG_NULL_POINTER "(null)"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <libft.h>
# include <ft_printf_param.h>
# include <ft_printf_call.h>
# include <ft_printf_debug.h>

# include <stdio.h> // TO DELETE
# include <locale.h> // TO DELETE

//ft_printf
int				ft_printf(const char *str, ...);
int				ft_printf_do(t_param *param, va_list *list);
void			ft_display_param(t_param *param);

//ft_printf_tools
int				ft_printf_atoi(const char *str);
char			ft_printf_int_to_hex(unsigned int i);
void			ft_printf_str_toupper(char **str);
int				ft_printf_wstrlen(wchar_t *str);
void			ft_printf_putwstr(wchar_t *str);
#endif