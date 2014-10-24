#include <ft_printf.h>

void	ft_printf_string(char **s, t_param *param)
{
	int		len_value;
	int		width;
	int		pos_percent;
	char	*str;

	len_value = ft_printf_strlen(param->value);
	width = ft_printf_atoi(param->width);
	pos_percent = 0;
	str = *s;
	while (str[pos_percent] && str[pos_percent] != '%')
		pos_percent++;
	write(1, str, pos_percent);
	str += pos_percent + ft_printf_get_format_length(param) + 1;
	while (width > len_value)
	{
		if (param->flag == '0')
			write(1, &param->flag, 1);
		else
			write(1, " ", 1);			
		width--;
	}
	write(1, param->value, len_value);
	*s = str;
}

char	*ft_printf_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	len = ft_printf_strlen(s1) + ft_printf_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	if (str)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			str[i + j] = s2[j];
			j++;
		}
	}
	return (str);
}