/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 00:08:29 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#ifdef _USER__
#	define PRINTF_MACRO printf
#else
#	define PRINTF_MACRO printf
#endif

/*static void	print_test(char *str)
{
#ifdef _USER__
	write(1, str, my_strlen(str));
	write(1, " : ", 3);
#else
	printf("%s : ", str);
#endif
}*/

/*static void	print_ret(int ret)
{
#ifdef _USER__
	write(1, " ", 1);
	my_put_nbr(ret);
	write(1, "\n", 1);
#else
	printf(" %d\n", ret);
#endif
}*/

int	main(void)
{
	int ret;
	void	*ptr;

	ptr = (void *)0x0000ffff0000;
	//#include "test.c"
	printf("size of ulong int:%ld\n", sizeof(unsigned long int));
	ft_printf("ft adress of ret: '%p'\n", ptr);
	printf("adress of ret: '%p'\n", ptr);/*
	ret = ft_printf("String: %s\n", "42");
	ft_printf("ret: %d\n", ret);
	ret = ft_printf("String: %s\n", NULL);
	ft_printf("ret: %d\n", ret);
	ret = ft_printf("String: %s\n", "");
	ft_printf("ret: %d\n", ret);
	ret = ft_printf("Integer: % 5d\n", 42);
	ft_printf("ret: %d\n", ret);
	ret = ft_printf("Integer: %d\n", -42);
	ft_printf("ret: %d\n", ret);
	ret = ft_printf("Integer: %ld\n", (long int)42);
	ft_printf("ret: %d\n", ret);
	ret = ft_printf("Integer: %lld\n", (long long int)42);
	ft_printf("ret: %d\n", ret);
	ret = ft_printf("Integer: %hd\n", (unsigned long int)42);
	ft_printf("ret: %d\n", ret);
	ret = ft_printf("Integer: %hhd\n", (unsigned long long int)42);
	ft_printf("ret: %d\n", ret);

	printf("%010d\n", 42);
	printf("%010s\n", "test");*/
	return (0);
}
/*
int		main(int argc, char **argv)
{
	int	ret;
	int	ret_ft;
	(void)argc;
	(void)argv;
	printf("Tests de printf:\n");
	ret_ft = printf("FT: i:%i, d:%d, s:%s, c:%c\n", 1024, 2048, "ABCDEF", 'Z');
	printf("nb char écris: %i\n", ret_ft);
	ret = printf("PR: i:%i, d:%d, s:%s, c:%c\n", 1024, 2048, "ABCDEF", 'Z');
	printf("nb char écris: %i\n", ret);

	return (0);
}*/
	
