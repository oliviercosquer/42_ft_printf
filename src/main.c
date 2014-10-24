#include <ft_printf.h>

int		main(int argc, char **argv)
{
	//int	ret;
	int	ret_ft;
	(void)argc;
	(void)argv;
	//printf("Tests de ft_printf:\n");
	/*ret_ft = ft_printf("FT: i:%i, d:%d, s:%s, c:%c\n", 1024, 2048, "ABCDEF", 'Z');
	ft_printf("nb char écris: %i\n", ret_ft);*/
	ret_ft = ft_printf("");
	ft_printf("nb char écris: %i\n", ret_ft);
	/*ret = printf("PR: i:%i, d:%d, s:%s, c:%c\n", 1024, 2048, "ABCDEF", 'Z');
	ft_printf("nb char écris: %i\n", ret);*/
	return (0);
}