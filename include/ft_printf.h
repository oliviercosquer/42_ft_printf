/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 22:53:58 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MSG_NULL_POINTER "(null)"
# define VALID_SPECIFIER "dDiuUoOxXfFeEgGaAcCsSpn%"
# define VALID_LENGTH "hllljztL"
# define VALID_FLAGS "-+ #0"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <libft.h>
# include <stdio.h> // TO DELETE
typedef struct	s_param
{
	char			*value;
	char			flag;
	char			*width;
	char			*precision;
	char			*specifier;
	char			*specifier_length;
	struct s_param	*next;
}				t_param;
typedef char	*(*t_print_func)(int *i, va_list *list);
typedef void	(*t_call_func)(t_param *p, int *i, va_list *list);

//ft_params
t_param			*ft_printf_get_params(char **str, int *total_char);
void			ft_printf_del_params(t_param **params);

//ft_params_check
int				ft_is_format_valid(char *str);
int				ft_has_flag(char *str);
int				ft_has_width(char *str);
int				ft_has_precision(char *str);
int				ft_is_valid_specifier(char c);

//ft_params_get
char			ft_get_flag(char *str);
char			*ft_get_width(char **str);
char			*ft_get_precision(char **str);
char			*ft_get_specifier(char **str, t_param *param);
int				ft_printf_get_format_length(t_param *param);

//ft_printf
int				ft_printf(const char *str, ...);

//ft_printf_call
void			ft_printf_call(t_param *param, int *total_char, va_list *l);

//ft_printf_double
char			*ft_printf_print_double_default(int *total_char, va_list *l);
char			*ft_printf_print_long_double(int *total_char, va_list *l);

//ft_printf_flag
void			ft_printf_flag_numeric(t_param *param, int *total_char, char *str);

//ft_printf_integer
char			*ft_printf_print_integer_default(int *total_char, va_list *l);
char			*ft_printf_print_long_integer(int *total_char, va_list *l);
char			*ft_printf_print_long_long_integer(int *total_char, va_list *l);
char			*ft_printf_print_short_integer_default(int *total_char, va_list *list);
char			*ft_printf_print_ushort_integer(int *total_char, va_list *list);

//ft_printf_integer2
char			*ft_printf_print_uinteger(int *total_char, va_list *list);
char			*ft_printf_print_long_uinteger(int *total_char, va_list *list);

//ft_printf_integer_signed
char			*ft_printf_lint_itoa(long int n);
char			*ft_printf_long_lint_itoa(long int n);

//ft_printf_integer_unsigned
char			*ft_printf_unsigned_itoa(unsigned int n);
char			*ft_printf_ulong_itoa(unsigned long int n);

//ft_printf_string
void			ft_printf_print_octal(t_param *param, int *total_char, va_list *l);
void			ft_printf_print_pointer(t_param *param, int *total_char, va_list *l);
void			ft_printf_print_hex_int(t_param *param, int *total_char, va_list *l);

//ft_printf_tools
int				ft_printf_atoi(const char *str);
char			ft_printf_int_to_hex(unsigned int i);
#endif