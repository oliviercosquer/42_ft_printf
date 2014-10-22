#include <ft_printf.h>

int	ft_printf_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}