#include <ft_printf.h>

void	ft_printf_put(va_list *l, t_param *param)
{
	char	specifier;

	if (param)
	{
		specifier = *(param->specifier);
		if (specifier == 'd' || specifier == 'i')
			ft_printf_put_di(l, param);
		if (specifier == 's')
			ft_printf_put_s(l, param);
		if (specifier == 'c')
			ft_printf_put_c(l, param);
	}
}

void	ft_printf_put_di(va_list *l, t_param *param)
{
	if (!param->specifier_length)
	{
		ft_printf_put_int(param, va_arg(l, int));
	}
	else
	{
		if (*(param->specifier_length) == 'h')
			ft_printf_put_int(param, va_arg(l, int));
	}
}

void	ft_printf_put_s(va_list *l, t_param *param)
{
	//va_list	list;
	char	*str;

	//va_copy(list, *l);
	str = va_arg(*l, char *);
	write (1, str, ft_printf_strlen(str));
	(void)param;
	//va_end(list);
}

void	ft_printf_put_c(va_list *l, t_param *param)
{
	char	c;
	//va_list	list;

	//va_copy(list, *l);
	c = (char)va_arg(*l, int);
	write(1, &c, 1);
	(void)param;
	//va_end(list);
}