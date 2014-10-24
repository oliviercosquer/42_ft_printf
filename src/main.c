/*#include <ft_printf.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("TEST printf:\n");
	printf("Avant %-6d Après %ilol \n", 1024, 2048);
	printf("Avant % 6d Après %ilol \n", 1024, 2048);
	printf("Avant %+6d Après %ilol \n", 1024, 2048);
	printf("Avant %06d Après %ilol \n", 1024, 2048);
	printf("TEST ft_printf:\n");
	ft_printf("Avant %-6d Après %ilol \n", 1024, 2048);
	ft_printf("Avant % 6d Après %ilol \n", 1024, 2048);
	ft_printf("Avant %+6d Après %ilol \n", 1024, 2048);
	ft_printf("Avant %06d Après %ilol \n", 1024, 2048);
	return (0);
}*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ft_printf.h>

#ifdef _FT_USER__
#	define PRINTF_MACRO ft_printf
#else
#	define PRINTF_MACRO ft_printf
#endif

static void	print_test(char *str)
{
#ifdef _FT_USER__
	write(1, str, my_strlen(str));
	write(1, " : ", 3);
#else
	printf("%s : ", str);
#endif
}

static void	print_ret(int ret)
{
#ifdef _FT_USER__
	write(1, " ", 1);
	my_put_nbr(ret);
	write(1, "\n", 1);
#else
	printf(" %d\n", ret);
#endif
}

int	main(void)
{
	#include "test.c"
	return (0);
}
