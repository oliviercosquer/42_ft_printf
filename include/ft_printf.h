/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/10/02 14:40:05 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MSG_NULL_POINTER "(null)"
# define VALID_SPECIFIER "dDiuUoOxXfFeEgGaAcCsSpn%"
# define SPECIAL_SPECIFIER "DUO"
# define VALID_LENGTH "hllljztL"
# define VALID_FLAGS "-+ #0"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <libft.h>
# include <stdio.h> // TO DELETE
# include <locale.h> // TO DELETE	
# define SEGV ft_putstr("segv\n");


typedef struct	s_param
{
	char			*value;
	char			*flag;
	char			*width;
	char			*precision;
	char			specifier;
	char			*specifier_length;
}				t_param;
typedef char	*(*t_print_func)(va_list *list);
typedef int		(*t_call_func)(t_param *p, va_list *list);
typedef int		(*t_flag_func)(t_param *param, char *str);

//ft_params
t_param			*ft_printf_get_params(char **str, int *total_char, va_list *list);
void			ft_printf_del_params(t_param **params);
void			ft_printf_param_find(char **str, int *total_char);
void			ft_printf_param_special(t_param *param);
t_param			*ft_printf_param_parse(char **str, va_list *list);
t_param			*ft_printf_new_param(void);

//ft_params_check
int				ft_is_format_valid(char *str);
int				ft_has_flag(char *str);
int				ft_has_width(char *str);
int				ft_has_precision(char *str);
int				ft_is_valid_specifier(char c);

//ft_params_get
char			*ft_get_flag(char *str);
char			*ft_get_width(char **str);
char			*ft_get_precision(char **str);
char			*ft_get_specifier(char **str, t_param *param);
int				ft_printf_get_format_length(t_param *param);

//ft_printf
int				ft_printf(const char *str, ...);
void			ft_display_param(t_param *param);

//ft_printf_call
int				ft_printf_call(t_param *param, va_list *l);
int				ft_printf_print_double(t_param *param, va_list *l);
int				ft_printf_print_string(t_param *param, va_list *l);

//ft_printf_call2
int				ft_printf_print_o(t_param *param, va_list *l);
int				ft_printf_print_wstring(t_param *param, va_list *l);
int				ft_printf_print_octal(t_param *param, va_list *l);
int				ft_printf_print_hex(t_param *param, va_list *l);

//ft_printf_call3
t_print_func	ft_printf_get_call_integer(char *specifier_length);

//ft_printf_call_integer
int				ft_printf_print_integer(t_param *param, va_list *l);
int				ft_printf_print_unsigned_integer(t_param *param, va_list *l);
//int				ft_printf_print_d(t_param *param, va_list *l);
int				ft_printf_print_u(t_param *param, va_list *l);

//ft_printf_call_string

//ft_printf_double
char			*ft_printf_print_double_default(va_list *l);
char			*ft_printf_print_long_double(va_list *l);

//ft_printf_flag
t_flag_func		ft_printf_get_flag_func(char specifier);
char			*ft_printf_flag_space(char *str, int len);

//ft_printf_flag_integer
char			*ft_printf_flag_integer_minus(char *str, int len);
char			*ft_printf_flag_integer_plus(char *str);
char			*ft_printf_flag_integer_0(char *str, int len);
int				ft_printf_flag_integer(t_param *param, char *str);

//ft_printf_flag_string
int				ft_printf_flag_string(t_param *param, char *str);

//ft_printf_flag_c
int				ft_printf_flag_c(t_param *param, char *str);

//ft_printf_hex
char			*ft_printf_print_hex_default(va_list *l);
char			*ft_printf_print_long_hex(va_list *l);
char			*ft_printf_print_long_long_hex(va_list *l);
char			*ft_printf_print_short_hex(va_list *l);

//ft_printf_integer
char			*ft_printf_print_integer_default(va_list *l);
char			*ft_printf_print_long_integer(va_list *l);
char			*ft_printf_print_long_long_integer(va_list *l);
char			*ft_printf_print_short_integer_default(va_list *list);
char			*ft_printf_print_ushort_integer(va_list *list);

//ft_printf_integer2
char			*ft_printf_print_uinteger(va_list *list);
char			*ft_printf_print_long_uinteger(va_list *list);
char			*ft_printf_print_integer_n(va_list *list);

//ft_printf_integer_signed
char			*ft_printf_lint_itoa(long int n);
char			*ft_printf_long_lint_itoa(long int n);

//ft_printf_integer_unsigned
char			*ft_printf_unsigned_itoa(unsigned int n);
char			*ft_printf_ulong_itoa(unsigned long int n);

//ft_printf_octal
char			*ft_printf_print_octal_default(va_list *l);
char			*ft_printf_print_long_octal(va_list *l);
char			*ft_printf_print_long_octal2(va_list *l);
char			*ft_printf_print_long_long_octal(va_list *l);

//ft_printf_param_parse
char			*ft_printf_param_parse_flag(char **str);
char			*ft_printf_param_parse_width(char **str, va_list *list);
char			*ft_printf_param_parse_precision(char **str, va_list *list);
char			*ft_printf_param_parse_specifier_length(char **str);
char			ft_printf_param_parse_specifier(char **str);

//ft_printf_string
int				ft_printf_print_pointer(t_param *param, va_list *l);
int				ft_printf_print_string_default(t_param *param, char *str);
int				ft_printf_print_c(t_param *param, char c);
int				ft_printf_print_wchar_c(t_param *param, wchar_t c);
int				ft_printf_print_wchar_default(t_param *param, wchar_t *str);

//ft_printf_tools
int				ft_printf_atoi(const char *str);
char			ft_printf_int_to_hex(unsigned int i);
void			ft_printf_str_toupper(char **str);
int				ft_printf_wstrlen(wchar_t *str);
void			ft_printf_putwstr(wchar_t *str);
#endif