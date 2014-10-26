/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:55 by ocosquer          #+#    #+#             */
/*   Updated: 2014/10/26 02:08:06 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putint(void *n, t_param *param)
{
	int	nbr;

	nbr = *(int *)n;
	(void)param;
	(void)nbr;
}

void	ft_putlong(void *n, t_param *param)
{
	long	nbr;

	nbr = *(long *)n;
	(void)param;
	(void)nbr;
}

void	ft_putdouble(void *n, t_param *param)
{
	double	nbr;

	nbr = *(double *)n;
	(void)param;
	(void)nbr;
}
