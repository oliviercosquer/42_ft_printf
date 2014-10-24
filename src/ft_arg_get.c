#include <ft_printf.h>

char	*ft_printf_get_arg(va_list *l, t_param *param)
{
	char	*tmp;

	if (param->width && *(param->width) == '*')
	{
		free(param->width);
		tmp = ft_printf_itoa(va_arg(*l, int));
		param->width = tmp;
	}
	if (param->precision && *(param->precision) == '*')
	{
		free(param->precision);
		tmp = ft_printf_itoa(va_arg(*l, int));
		param->precision = tmp;
	}	
	return (ft_printf_put(l, param));
}