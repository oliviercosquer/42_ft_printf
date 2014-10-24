# include <ft_printf.h>

char	*ft_printf_get_signed_int(t_param *param, int n)
{	char	*nbr;

	nbr = ft_printf_itoa(n);
	if (param->flag == '+')
	{
		if (n >= 0)
			nbr = ft_printf_strjoin("+", nbr);
	}
	if (param->flag == ' ' && n > 0)
		nbr = ft_printf_strjoin(" ", nbr);
	return (nbr);
}

char	*ft_printf_get_unsigned_int(t_param *param, unsigned int n)
{
	char			*nbr;

	if (param->flag == '+')
		write(1, "+", 1);
	if (param->flag == ' ')
		write(1, " ", 1);
	nbr = ft_printf_unsigned_itoa(n);
	return (nbr);
}