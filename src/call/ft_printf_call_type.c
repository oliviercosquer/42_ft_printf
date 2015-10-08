/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 11:36:23 by olivier           #+#    #+#             */
/*   Updated: 2015/10/08 18:55:08 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_call.h>
#include <ft_printf_debug.h>

t_convert_func	ft_printf_call_get_type_func(t_param *param)
{
	//@TODO
	static	t_convert_func	func[256][256];
	//t_convert_func			the_function;

	if (!func['i'][0])
		ft_printf_call_type_func_init(func);
	/*else
		the_function = func[param->specifier][0];*/
	return (func[param->specifier][0]);
}

void			ft_printf_call_type_func_init(t_convert_func function_array[256][256])
{
	//@TODO
	function_array['s'][0] = &ft_printf_convert_string;
	function_array['S'][0] = NULL;

	function_array['d'][0] = &ft_printf_convert_integer;
	function_array['d']['h'] = &ft_printf_convert_short_integer;
	function_array['d']['H'] = &ft_printf_convert_short_integer;
	function_array['d']['l'] = &ft_printf_convert_long_integer;
	function_array['d']['L'] = &ft_printf_convert_long_long_integer;

	function_array['i'][0] = &ft_printf_convert_integer;
	function_array['i']['h'] = &ft_printf_convert_short_integer;
	function_array['i']['H'] = &ft_printf_convert_short_integer;
	function_array['i']['l'] = &ft_printf_convert_long_integer;
	function_array['i']['L'] = &ft_printf_convert_long_long_integer;
	//@TODO hhd lld / hhi hhl
	function_array['D'][0] = NULL;


	function_array['o'][0] = &ft_printf_convert_octal;
	function_array['O'][0] = NULL;

	function_array['u'][0] = &ft_printf_convert_unsigned_integer;
	function_array['u']['h'] = &ft_printf_convert_short_unsigned_integer;
	function_array['u']['l'] = &ft_printf_convert_long_unsigned_integer;
	function_array['U'][0] = NULL;

	function_array['x'][0] = NULL;
	function_array['X'][0] = NULL;

	function_array['c'][0] = NULL;
	function_array['C'][0] = NULL;
}