#include <ft_printf.h>

void	ft_printf_putstr(void *s, t_param *param)
{
	char	*str;

	(void)param;
	str = (char *)s;
	if (str)
		write(1, str, ft_printf_strlen(str));
	else
		write(1, MSG_NULL_POINTER, ft_printf_strlen(MSG_NULL_POINTER));
}

int		ft_printf_strlen(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

int		ft_printf_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (0);
		str++;
	}
	return (0);
}

char	*ft_printf_strdup(char *str)
{
	char	*str_dup;
	int		len;

	len = ft_printf_strlen(str);
	str_dup = NULL;
	if (len)
	{
		str_dup = (char *)malloc(sizeof(char) * len + 1);
		if (str_dup)
		{
			str_dup[len] = '\0';
			while (len >= 0)
			{
				str_dup[len] = str[len];
				len--;
			}
		}
	}
	return (str_dup);
}