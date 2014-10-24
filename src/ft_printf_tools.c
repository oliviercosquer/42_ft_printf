#include <ft_printf.h>

int		ft_printf_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_printf_atoi(const char *str)
{
	int	value;

	value = 0;
	while (str && *str)
	{
		value = (value * 10) + (*str - '0');
		str++;
	}
	return (value);
}

char	*ft_printf_itoa(int n)
{
	char	*nbr;
	int		len;
	int		rest;
	int		negative;

	len = ft_printf_getintlength(n);
	negative = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	nbr = (char *)malloc(sizeof(char) * len + 1);
	if (nbr)
	{
		while (len >= 0)
		{
			rest = n % 10;
			nbr[len] = '0' + rest;
			n = n / 10;
			len--;
		}
		nbr[len] = '\0';
		if (negative)
			nbr[0] = '-';
	}
	return (nbr);
}

int		ft_printf_getintlength(int n)
{	
	int		len;
	int		tmp;

	len = 0;
	tmp = n;
	if (n < 0)
		len = 1;
	while (tmp >= 10)
	{
		len++;
		if (tmp >= 10)
			tmp = tmp / 10;
		else
			tmp = -1;
	}
	return (len);
}

int		ft_printf_get_format_length(t_param *param)
{
	int	len;

	len = 0;
	if (param->flag)
		len++;
	if (param->width)
	{
		if (*(param->width) == '*')
			len++;
		else
			len += ft_printf_strlen(param->width);
	}
	if (param->specifier)
		len++;
	if (param->specifier_length)
		len += ft_printf_strlen(param->specifier_length);
	return (len);
}