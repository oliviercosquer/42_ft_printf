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
	int		nb_char;

	str = (char *)s;
	if (ft_printf_strlen(str) > 2)
		params = ft_get_params(str);
	else
		params = NULL;
	nb_char = 0;
	va_start(list, s);
	while (params)
	{
		params->value = ft_printf_get_arg(&list, params);
		nb_char += ft_printf_string(&str, params);
		params = params->next;
	}
	nb_char += ft_printf_strlen(str);
	write(1, str, ft_printf_strlen(str));
	va_end(list);
	return (nb_char);
}