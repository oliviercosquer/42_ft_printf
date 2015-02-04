/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/03 21:15:52 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#ifdef _FT_USER__
#	define PRINTF_MACRO ft_printf
#else
#	define PRINTF_MACRO ft_printf
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
	ft_printf("TEST %d", -12);
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
	printf("Tests de ft_printf:\n");
	ret_ft = ft_printf("FT: i:%i, d:%d, s:%s, c:%c\n", 1024, 2048, "ABCDEF", 'Z');
	ft_printf("nb char écris: %i\n", ret_ft);
	ret = printf("PR: i:%i, d:%d, s:%s, c:%c\n", 1024, 2048, "ABCDEF", 'Z');
	ft_printf("nb char écris: %i\n", ret);

	return (0);
}*/
	
