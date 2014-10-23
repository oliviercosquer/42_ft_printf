#include <ft_printf.h>

void	ft_display_param(t_param *param)
{
	if (param)
	{
		printf("Flag:%c, Width:%s, Precision:%s, Specifier:%s, Length:%s\n",
			param->flag, param->width, param->precision, param->specifier,
			param->specifier_length);
	}
}

int		ft_printf(const char *str, ...)
{
	va_list	list;
	t_param	*params;

	params = ft_get_params((char *)str);
	va_start(list, str);
	while (params)
	{
		ft_printf_get_arg(&list, params);
		ft_display_param(params);
		params = params->next;
	}
	write(1, "\n", 1);
	va_end(list);
	return (0);
}