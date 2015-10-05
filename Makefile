NAME = libftprintf.a
INCLUDE_PATH = -I./include/ -I./libft/includes
LIBFT_DIR = ./libft
SRC_PATH = ./src/
SRC_FILES =	call/ft_printf_call_flag.c \
			call/ft_printf_call_precision.c \
			call/ft_printf_call_type.c \
			call/ft_printf_call_width.c \
			convert/ft_printf_convert_double.c \
			convert/ft_printf_convert_hex.c \
			convert/ft_printf_convert_integer.c \
			convert/ft_printf_convert_octal.c \
			convert/ft_printf_convert_string.c \
			convert/ft_printf_convert_unsigned_integer.c \
			param/ft_printf_param.c \
			param/ft_printf_param_check.c \
			param/ft_printf_param_parse.c \
			param/ft_printf_param_parse_specifiers.c
BASE_FILES = $(addprefix $(SRC_PATH),$(SRC_FILES))
SRC = $(BASE_FILES)
FLAGS = #-Wall -Werror -Wextra

all: libft_all ${NAME}

${NAME}:
	@echo compilation of $(NAME)
	@gcc -c $(INCLUDE_PATH) $(FLAGS)  $(SRC)
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
