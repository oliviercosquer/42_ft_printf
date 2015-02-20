NAME = libftprintf.a
INCLUDE_PATH = -I./include/ -I./libft/includes
LIBFT_DIR = ./libft
SRC_PATH = ./src/
SRC_FILES =	ft_printf.c \
			ft_printf_call.c \
			ft_printf_str.c \
			ft_params_check.c \
			ft_printf_integer.c \
			ft_printf_double.c \
			ft_params_get.c ft_params_get2.c ft_params.c \
			ft_printf_tools.c ft_printf_get.c ft_printf_get_float.c \
			ft_arg_get.c ft_printf_put_int.c ft_printf_tools_unsigned.c
BASE_FILES = $(addprefix $(SRC_PATH),$(SRC_FILES))
SRC = $(BASE_FILES)

all: libft_all ${NAME}

${NAME}:
	@echo compilation of $(NAME)
	@gcc -c $(INCLUDE_PATH) -Wall -Werror -Wextra $(SRC) -L./libft -lft
	@ar rc ./libft/libft.a $(SRC_FILES:.c=.o)
	@cp ./libft/libft.a ./libftprintf.a
	@echo Compilation done!

clean: libft_clean
	@echo Delete .o files
	@rm -f $(SRC_FILES:.c=.o)
	@echo Delete done!

fclean: libft_fclean clean
	@echo Delete $(NAME)
	@rm -f $(NAME)
	@echo Delete done!

re: libft_re fclean all

libft_all:
	@make -C $(LIBFT_DIR) all

libft_clean:
	@make -C $(LIBFT_DIR) clean

libft_fclean:
	@make -C $(LIBFT_DIR) fclean

libft_re:
	@make -C $(LIBFT_DIR) re