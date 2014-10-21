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