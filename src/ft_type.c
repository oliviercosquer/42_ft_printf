#include <ft_printf.h>

t_func	ft_get_type(char c)
{
	static	t_func	types[255];

	if (!types[0])
	{
		ft_init_base_func(types);
		ft_printf_putstr("static array initialized!\n", NULL);
	}
	return (types[(int)c]);
}

void	ft_init_base_func(t_func *types)
{
	types['d'] = ft_putint;
	types['i'] = ft_putint;
	types['s'] = ft_printf_putstr;
}