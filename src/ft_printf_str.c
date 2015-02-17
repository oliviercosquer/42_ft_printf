/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/04 02:29:59 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_putstr(void *s, t_param *param)
{
	char	*str;

	(void)param;
	str = (char *)s;
	if (str)
		write(1, str, ft_strlen(str));
	else
		write(1, MSG_NULL_POINTER, ft_strlen(MSG_NULL_POINTER));
}

int		ft_printf_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_printf_strdup(char *str)
{
	char	*str_dup;
	int		len;

	len = ft_strlen(str);
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

char	*ft_printf_strsub(char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str)
	{
		while (str && s[i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[len] = '\0';
	}
	return (str);
}
