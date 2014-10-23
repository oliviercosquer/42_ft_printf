#include <ft_printf.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("%d%i\n", -1, 1234);
	return (0);
}