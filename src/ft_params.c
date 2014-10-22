#include <ft_printf.h>

t_param	*ft_new_param(void)
{	
	t_param	*params;

	params = (t_param *)malloc(sizeof(t_param));
	if (params)
	{
		params->flag = '0';
		params->width = NULL;
		params->precision = NULL;
		params->next = NULL;
		params->specifier = NULL;
		params->specifier_length = NULL;
		return (params);
	}
	return (NULL);
}

void	ft_add_param(t_param *first, t_param *new_param)
{
	if (first)
	{
		while (first->next)
			first = first->next;
		first->next = new_param;
	}
}