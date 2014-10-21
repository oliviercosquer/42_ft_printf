#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MSG_NULL_POINTER "(null)"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h> // TO DELETE
typedef struct	s_param
{
	void			*value;
	char			flag;
	int				width;
	int				precision;
	struct s_param	*next;
}				t_param;
typedef void (*t_func)(void *, t_param *param);

//ft_params
t_param			*ft_new_param(void);
t_param			*ft_get_next_param(char *str);
void			ft_add_param(t_param *first, t_param *new_param);

//ft_params_check
int				ft_is_format_valid(char *str);
int				ft_has_flag(char *str);
int				ft_has_width(char *str);
int				ft_has_precision(char *str);
int				ft_is_valid_flag(char c);

//ft_printf_str
void			ft_printf_putstr(void *s, t_param *param);
int				ft_printf_strlen(char *str);
int				ft_printf_strchr(char *str, char c);
char			*ft_printf_strdup(char *str);

//ft_putint
void			ft_putint(void *n, t_param *param);
void			ft_putlong(void *n, t_param *param);
void			ft_putdouble(void *n, t_param *param);

//ft_type
void			ft_init_base_func(t_func *types);
t_func			ft_get_type(char c);
#endif