/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 11:36:23 by olivier           #+#    #+#             */
/*   Updated: 2015/10/05 13:12:11 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_call.h>

t_convert_func	*ft_printf_call_get_type_func(t_param *param)
{
	//@TODO
	static	t_convert_func	func[256][256];

	if (!func[i][0])
		ft_printf_call_type_func_init(func);
	else
		func = func[param->specifier];
	return (func);
}

void			ft_printf_call_type_func_init(static t_convert_func **function_array);
{
	//@TODO
	function_array['s'][0] = &ft_printf_convert_string;
	function_array['S'][''] = NULL;

	function_array['d'][0] = &ft_printf_convert_integer;
	function_array['d']['h'] = &ft_printf_convert_short_integer;
	function_array['d']['l'] = &ft_printf_convert_long_integer;
	function_array['i'][0] = &ft_printf_convert_integer;
	//@TODO hhd lld / hhi hhl
	function_array['D'][''] = NULL;


	function_array['o'][0] = &ft_printf_convert_octal;
	function_array['O'][''] = NULL;

	function_array['u'][0] = &ft_printf_convert_unsigned_integer;
	function_array['u']['h'] = &ft_printf_convert_short_unsigned_integer;
	function_array['u']['l'] = &ft_printf_convert_long_unsigned_integer;
	function_array['U'][''] = NULL;

	function_array['x'][''] = NULL;
	function_array['X'][''] = NULL;

	function_array['c'][''] = NULL;
	function_array['C'][''] = NULL;
}