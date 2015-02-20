/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/20 05:17:50 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#ifdef _FT_USER__
#	define PRINTF_MACRO printf
#else
#	define PRINTF_MACRO printf
#endif

/*static void	print_test(char *str)
{
#ifdef _FT_USER__
	write(1, str, my_strlen(str));
	write(1, " : ", 3);
#else
	printf("%s : ", str);
#endif
}*/

/*static void	print_ret(int ret)
{
#ifdef _FT_USER__
	write(1, " ", 1);
	my_put_nbr(ret);
	write(1, "\n", 1);
#else
	printf(" %d\n", ret);
#endif
}*/

int	main(void)
{
	//#include "test.c"
	ft_printf("%i%d%li%ld%lli%lld", 1, 2, 3, 4, 5, 6, 7);
	return (0);
}
/*
int		main(int argc, char **argv)
{
	int	ret;
	int	ret_ft;
	(void)argc;
	(void)argv;
	printf("Tests de ft_printf:\n");
	ret_ft = ft_printf("FT: i:%i, d:%d, s:%s, c:%c\n", 1024, 2048, "ABCDEF", 'Z');
	ft_printf("nb char écris: %i\n", ret_ft);
	ret = printf("PR: i:%i, d:%d, s:%s, c:%c\n", 1024, 2048, "ABCDEF", 'Z');
	ft_printf("nb char écris: %i\n", ret);

	return (0);
}*/
	
