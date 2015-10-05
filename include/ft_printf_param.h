/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_param.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 12:09:29 by olivier           #+#    #+#             */
/*   Updated: 2015/10/05 14:24:04 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARAM_H
# define FT_PRINTF_PARAM_H
# include <ft_printf.h>

typedef struct	s_param
{
	char			*value;
	char			*flag;
	char			*width;
	char			*precision;
	char			specifier;
	char			*specifier_length;
}				t_param;

//param
t_param			*ft_printf_param_new(void);
void			ft_printf_param_del(t_param **params);

//param parse
t_param			*ft_printf_param_get(char **str, int *total_char, va_list *list);
t_param			*ft_printf_param_parse(char **str, va_list *list);
void			ft_printf_param_find_next(char **str, int *total_char);
void			ft_printf_param_special(t_param *param);

//parse specifiers
char			*ft_printf_param_parse_flag(char **str);
char			*ft_printf_param_parse_width(char **str, va_list *list);
char			*ft_printf_param_parse_precision(char **str, va_list *list);
char			*ft_printf_param_parse_specifier_length(char **str);
char			ft_printf_param_parse_specifier(char **str);

//param check
int				ft_is_format_valid(char *str);
int				ft_has_flag(char *str);
int				ft_has_width(char *str);
int				ft_has_precision(char *str);
int				ft_is_valid_specifier(char c);
#endif