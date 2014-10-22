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
			has_width++;
		}
	return (has_width);
}

int		ft_has_precision(char *str)
{
	int		has_precision;
	char	*tmp;

	has_precision = 0;
	tmp = str + 1;
	tmp += ft_has_flag(str);
	tmp += ft_has_width(str);
	if (*tmp == '.')
	{
		tmp++;
			has_precision++;
		if (*tmp == '*')
		{
			has_precision++;
			tmp++;
		}
		else
			while (ft_printf_isdigit(*tmp))
			{
				has_precision++;
				tmp++;
			}
	}
	return (has_precision);
}

int		ft_is_valid_specifier(char c)
{
	int			isvalid;

	isvalid = 0;
	isvalid = ft_printf_strchr(VALID_SPECIFIER, c);
	return (isvalid);
}