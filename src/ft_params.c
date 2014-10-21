t_param	*ft_new_param(void)
{	
	t_param	*params;

	params = (t_param *)malloc(sizeof(t_param));
	if (params)
	{
		params->flag = NULL;
		params->width = -1;
		params->precision = -1;
		params->next = NULL;
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

t_param	*ft_get_next_param(char *str)
{
	t_param	*params;

	params = ft_new_param();
	if (params)
	{
		while (str && *str != "%")
			str++;
		if (ft_is_valid_flag(*str))
			params = *str;
		str++;
		return (params);
	}
	return (NULL);
}