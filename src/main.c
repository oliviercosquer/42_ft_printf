#include <ft_printf.h>

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
}