/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/20 07:36:16 by olivier          ###   ########.fr       */
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
//NEW
typedef void	(*t_print_func)(t_param *p, int *i, va_list *list);
typedef void	(t_call_func)(t_param *p, int *i, va_list *list);

int				ft_printf(const char *str, ...);

//ft_printf_call
void			ft_printf_call(t_param *param, int *total_char, va_list *l);

//ft_printf_integer
void			ft_print_print_integer_default(t_param *param, int *total_char, va_list *l);
void			ft_print_print_long_integer_default(t_param *param, int *total_char, va_list *l);
void			ft_print_print_long_long_integer_default(t_param *param, int *total_char, va_list *l);

//ft_printf_double
void			ft_print_print_double_default(t_param *param, int *total_char, va_list *l);


//ft_params
t_param			*ft_printf_new_param(void);
void			ft_printf_add_param(t_param *first, t_param *new_param);
t_param			*ft_printf_get_next_param(char *str);
t_param			*ft_printf_get_params(char **str, int *total_char);
void			ft_printf_del_params(t_param **params);

//ft_params_check
int				ft_is_format_valid(char *str);
int				ft_has_flag(char *str);
int				ft_has_width(char *str);
int				ft_has_precision(char *str);
int				ft_is_valid_specifier(char c);

//ft_params_get2
char			ft_get_flag(char *str);
char			*ft_get_width(char **str);
char			*ft_get_precision(char **str);
char			*ft_get_specifier(char **str, t_param *param);
//ENDNEW

//ft_printf_str
void			ft_printf_putstr(void *s, t_param *param);
int				ft_printf_string(char **s, t_param *param);
int				ft_printf_padding(t_param *param);

//ft_printf_tools
int				ft_printf_get_format_length(t_param *param);
int				ft_printf_atoi(const char *str);

//ft_printf_tools_signed
int				ft_printf_lint_length(long int n);
char			*ft_printf_lint_itoa(long int n);

//ft_printf_tools_unsigned
int				ft_printf_uint_length(unsigned int n);
char			*ft_printf_unsigned_itoa(unsigned int n);
int				ft_printf_ulint_length(unsigned long int n);
char			*ft_printf_ulint_itoa(unsigned long int n);

//ft_printf_get
char			*ft_printf_get(va_list *l, t_param *param);
char			*ft_printf_get_di(va_list *l, t_param *param);
char			*ft_printf_get_s(va_list *l, t_param *param);
char			*ft_printf_get_c(va_list *l, t_param *param);
char			*ft_printf_get_p(va_list *l, t_param *param);

//ft_printf_get_float
char			*ft_printf_get_float(va_list *l, t_param *param);

//ft_printf_put_int
char			*ft_printf_get_signed_int(t_param *param,int nbr);
char			*ft_printf_get_unsigned_int(t_param *param,unsigned int nbr);
char			*ft_printf_get_signed_long_int(t_param *param,long int nbr);
char			*ft_printf_get_unsigned_long_int(t_param *param,unsigned long int nbr);

//ft_arg_get
char			*ft_printf_get_arg(va_list *l, t_param *param);
void			ft_printf_get_arg_value(va_list *l, t_param *param);
#endif