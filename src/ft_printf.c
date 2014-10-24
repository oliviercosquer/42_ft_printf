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

int		ft_printf(const char *s, ...)
{
	va_list	list;
	t_param	*params;
	char	*str;

	str = (char *)s;
	params = ft_get_params(str);
	va_start(list, s);
	while (params)
	{
		//ft_display_param(params);
		params->value = ft_printf_get_arg(&list, params);
		ft_printf_string(&str, params);
		params = params->next;
	}
	write(1, str, ft_printf_strlen(str));
	va_end(list);
	return (0);
}