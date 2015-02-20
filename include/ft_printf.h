/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/20 08:56:52 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MSG_NULL_POINTER "(null)"
# define VALID_SPECIFIER "diuoxXfFeEgGaAcspn%"
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
typedef void	(*t_print_func)(t_param *p, int *i, va_list *list);
typedef void	(t_call_func)(t_param *p, int *i, va_list *list);

//ft_params
t_param			*ft_printf_new_param(void);
t_param			*ft_printf_get_next_param(char *str);
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
void			ft_printf_print_integer(t_param *param, int *total_char, va_list *l);
void			ft_printf_print_double(t_param *param, int *total_char, va_list *l);
void			ft_printf_print_string(t_param *param, int *total_char, va_list *l);
void			ft_printf_call(t_param *param, int *total_char, va_list *l);

//ft_printf_double
void			ft_printf_print_double_default(t_param *param, int *total_char, va_list *l);
void			ft_printf_print_long_double(t_param *param, int *total_char, va_list *l);
void			ft_printf_print_long_long_double(t_param *param, int *total_char, va_list *l);

//TO DELETE
//ft_printf_get_float
char			*ft_printf_get_float(va_list *l, t_param *param);

//ft_printf_print_integer
void			ft_printf_print_integer_default(t_param *param, int *total_char, va_list *l);
void			ft_printf_print_long_integer(t_param *param, int *total_char, va_list *l);
void			ft_printf_print_long_long_integer(t_param *param, int *total_char, va_list *l);
void			ft_printf_print_short_integer_default(t_param *param, int *total_char, va_list *list);
void			ft_printf_print_ushort_integer(t_param *param, int *total_char, va_list *list);

//TO DELETE
//ft_printf_put_int
char			*ft_printf_get_signed_int(t_param *param,int nbr);
char			*ft_printf_get_unsigned_int(t_param *param,unsigned int nbr);
char			*ft_printf_get_signed_long_int(t_param *param,long int nbr);
char			*ft_printf_get_unsigned_long_int(t_param *param,unsigned long int nbr);

//TO DELETE
//ft_printf_str
int				ft_printf_padding(t_param *param);

//TO DELETE
//ft_printf_tools
int				ft_printf_atoi(const char *str);

//TO DELETE
//ft_printf_tools_signed
int				ft_printf_lint_length(long int n);
char			*ft_printf_lint_itoa(long int n);

//TO DELETE
//ft_printf_tools_unsigned
int				ft_printf_unsigned_length(unsigned int n);
int				ft_printf_ulong_length(unsigned long int n);
char			*ft_printf_unsigned_itoa(unsigned int n);
char			*ft_printf_ulong_itoa(unsigned long int n);


#endif