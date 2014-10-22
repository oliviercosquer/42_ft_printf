#include <ft_printf.h>

void	ft_printf_put(t_param *param)
{
	char	specifier;

	if (param)
	{
		specifier = *(param->specifier);
		if (specifier == 'd' || specifier == 'i')
			ft_printf_put_di(param);
		if (specifier == 's')
			ft_printf_put_s(param);
		if (specifier == 'c')
			ft_printf_put_c(param);
	}
}

void	ft_printf_put_di(t_param *param)
{
	(void)param;	
}

void	ft_printf_put_s(t_param *param)
{
	char	*str;

	str = (char *)param->value;
	write (1, str, ft_printf_strlen(str));
	(void)param;
}

void	ft_printf_put_c(t_param *param)
{
	write(1, (char *)param->value, 1);
	(void)param;
}