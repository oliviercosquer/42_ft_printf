# include <ft_printf.h>

void	ft_printf_put_int(t_param *param, int n)
{
	int		length;
	char	*nbr;

	if (param->flag == '+')
	{
		if (n >= 0)
			write(1, "+", 1);
	}
	nbr = ft_printf_itoa(n);
	length = ft_printf_strlen(nbr);
	write(1, nbr, length);
	(void)param;
}