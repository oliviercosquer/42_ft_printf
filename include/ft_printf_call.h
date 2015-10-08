/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 11:37:22 by olivier           #+#    #+#             */
/*   Updated: 2015/10/08 18:54:41 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CALL_H
# define FT_PRINTF_CALL_H
# include <ft_printf_param.h>
# include <ft_printf_convert.h>

typedef	char	*(*t_convert_func)(va_list *list);
typedef	char	*(*t_do_func)(char **str);

t_convert_func	ft_printf_call_get_type_func(t_param *param);
void			ft_printf_call_type_func_init(t_convert_func function_array[256][256]);

t_do_func		ft_printf_call_get_flag_func(t_param *param);
void			ft_printf_call_flag_func_init(t_do_func **function_array);

t_do_func		ft_printf_call_get_precision_func(t_param *param);
void			ft_printf_call_precision_func_init(t_do_func **function_array);

t_do_func		ft_printf_call_get_width_func(t_param *param);
void			ft_printf_call_width_func_init(t_do_func **function_array);
#endif