/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/10/05 14:29:53 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MSG_NULL_POINTER "(null)"
# define VALID_SPECIFIER "dDiuUoOxXfFeEgGaAcCsSpn%"
# define SPECIAL_SPECIFIER "DUO"
# define VALID_LENGTH "hllljztL"
# define VALID_FLAGS "-+ #0"
# define SEGV ft_putstr("segv\n");
# define DEBUG 1
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <libft.h>
# include <stdio.h> // TO DELETE
# include <locale.h> // TO DELETE
# include <ft_printf_param.h>
# include <ft_printf_convert.h>	
# include <ft_printf_call.h>	

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