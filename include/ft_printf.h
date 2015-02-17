/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2014/11/16 16:42:06 by anonymous        ###   ########.fr       */
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
typedef void (*t_func)(void *, t_param *param);

int				ft_printf(const char *str, ...);

//ft_params
t_param			*ft_new_param(void);
void			ft_add_param(t_param *first, t_param *new_param);

//ft_params_check
int				ft_is_format_valid(char *str);
int				ft_has_flag(char *str);
int				ft_has_width(char *str);
int				ft_has_precision(char *str);
int				ft_is_valid_specifier(char c);

//ft_params_get
t_param			*ft_get_next_param(char **str);
t_param			*ft_get_params(char *str);

//ft_params_get2
char			ft_get_flag(char *str);
char			*ft_get_width(char **str);
char			*ft_get_precision(char **str);
char			*ft_get_specifier(char **str, t_param *param);

//ft_printf_str
void			ft_printf_putstr(void *s, t_param *param);
int				ft_printf_strchr(char *str, char c);
char			*ft_printf_strdup(char *str);
char			*ft_printf_strsub(char *s, int start, int len);

//ft_printf_str2
int				ft_printf_string(char **s, t_param *param);
char			*ft_printf_strjoin(char *s1, char *s2);
int				ft_printf_padding(t_param *param);

//ft_putint
void			ft_putint(void *n, t_param *param);
void			ft_putlong(void *n, t_param *param);
void			ft_putdouble(void *n, t_param *param);

//ft_type
void			ft_init_base_func(t_func *types);
t_func			ft_get_type(char c);

//ft_printf_tools
int				ft_printf_isdigit(char c);
void			ft_printf_reversestr(char *str);
int				ft_printf_getintlength(int n);
int				ft_printf_get_format_length(t_param *param);

//ft_printf_tools2
int				ft_printf_atoi(const char *str);
int				ft_printf_strequ(char *s1, char *s2);

//ft_printf_put
char			*ft_printf_put(va_list *l, t_param *param);
char			*ft_printf_get_di(va_list *l, t_param *param);
char			*ft_printf_get_s(va_list *l, t_param *param);
char			*ft_printf_get_c(va_list *l, t_param *param);

//ft_printf_put_int
char			*ft_printf_get_signed_int(t_param *param,int nbr);
char			*ft_printf_get_unsigned_int(t_param *param,unsigned int nbr);
char			*ft_printf_get_signed_long_int(t_param *param,long int nbr);
char			*ft_printf_get_unsigned_long_int(t_param *param,unsigned long int nbr);

//ft_printf_tools_unsigned
char			*ft_printf_unsigned_itoa(unsigned int n);
int				ft_printf_get_unsigned_intlength(unsigned int n);

//ft_arg_get
char			*ft_printf_get_arg(va_list *l, t_param *param);
void			ft_printf_get_arg_value(va_list *l, t_param *param);
#endif