/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 23:06:52 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <limits.h>

#ifdef _USER__
#	define PRINTF_MACRO ft_printf
#else
#	define PRINTF_MACRO ft_printf
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
	int	lol;

	printf("size lx:%ld\n", sizeof(unsigned long int));
	printf("size llx:%lld\n", sizeof(unsigned long long int));
	lol = printf("lx:%lx\n", 0);
	printf("ret:%d\n", lol);
	lol = printf("llx:%llx\n", ULLONG_MAX);
	printf("ret:%d\n", lol);
	lol = ft_printf("lx:%lx\n", 0);
	printf("ret:%d\n", lol);
	lol = ft_printf("llx:%llx\n", ULLONG_MAX);
	printf("ret:%d\n", lol);
	return (0);
	#include "test.c"
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
	
