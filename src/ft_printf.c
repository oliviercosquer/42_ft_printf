#include <ft_printf.h>

int		ft_printf(const char *str, ...)
{
	va_list	list;

	va_start(list, str);
	(void)str;
	return (0);
}
