#include <ft_printf.h>

int		ft_is_format_valid(char *str)
{
	int	valid;

	valid = (*str == '%') ? 1 : 0;
	str++;
	//flag
	valid = (valid && (*str == '-' || *str == '+' || *str == ' ')) ? 1 : 0;
	valid = (valid && (*str == '#' || *str == '0')) ? 1 : 0;
	str++;
	//width
	if (*str == '*')
		str++;
	else
		while (*str >= '0' && *str <= '9')
			str++;
	if (*str == '.' && *(str + 1) != '*' && *str >= '0' && *str <= '9')
	str++;
	return (valid);
}

int		ft_has_flag(char *str)
{
	int	has_flag;

	has_flag = 0;
	if (str)
	{
		str++;
		has_flag = (*str == '-' || *str == '+' || *str == ' ') ? 1 : 0;
		has_flag = (has_flag || *str == '#' || *str == '0') ? 1 : 0;
	}
	return (has_flag);
}

int		ft_has_width(char *str)
{
	int	has_width;

	has_width = 0;
	if (ft_has_flag(str))
		str++;
	str++;
	if (*str == '*')
		has_width = 1;
	else
		while (*str >= '0' && *str <= '9')
		{
			str++;
			has_width = 1;
		}
	return (has_width);
}

int		ft_has_precision(char *str)
{
	int	has_precision;

	(void)str;
	has_precision = 0;
	return (has_precision);
}

int		ft_is_valid_flag(char c)
{
	static char	*valid;
	int			isvalid;

	isvalid = 0;
	if (!valid)
		valid = ft_printf_strdup("diuoxXfFeEgGaAcspn%");
	isvalid = ft_printf_strchr(valid, c);
	return (isvalid);
}