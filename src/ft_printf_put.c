#include <ft_printf.h>

char	*ft_printf_put(va_list *l, t_param *param)
{
	char	specifier;
	char	*tmp;

	tmp = NULL;
	if (param)
	{
		specifier = *(param->specifier);
		if (specifier == 'd' || specifier == 'i')
			tmp = ft_printf_get_di(l, param);
		if (specifier == 's')
			tmp = ft_printf_get_s(l, param);
		if (specifier == 'c')
			tmp = ft_printf_get_c(l, param);
	}
	return (tmp);
}

char	*ft_printf_get_di(va_list *l, t_param *param)
{
	char	*tmp;

	tmp = NULL;
	if (!param->specifier_length)
	{
		tmp = ft_printf_get_signed_int(param, va_arg(l, int));
	}
	else
	{
		if (*(param->specifier_length) == 'h')
			tmp = ft_printf_get_signed_int(param, va_arg(l, int));
	}
	return (tmp);
}

char	*ft_printf_get_s(va_list *l, t_param *param)
{
	char	*str;

	str = va_arg(*l, char *);
	(void)param;
	return (str);
}

char	*ft_printf_get_c(va_list *l, t_param *param)
{
	char	c;
	char	*tmp;

	(void)param;
	c = (char)va_arg(*l, int);
	tmp = (char *)malloc(sizeof(char) * 2);
	if (tmp)
	{
		tmp[0] = c;
		tmp[1] = '\0';
	}
	return (tmp);
}