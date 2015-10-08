NAME = libftprintf.a

SRC_PATH = ./src/

SRC_NAME =	ft_printf.c \
			ft_printf_tools.c \
			call/ft_printf_call_flag.c \
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

OBJ_PATH = ./obj/

INC_PATH = ./include/ ./libft/includes

LIB_PATH = ./libft/

LIB_NAME = libft.a

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(SRC:.c=.o)
#$(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all: lib_all $(NAME)

$(NAME): $(OBJ)
	@ar rc ./libft/libft.a $(OBJ)
	@cp ./libft/libft.a ./libftprintf.a

%.o: %.c
	@$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<

clean: lib_clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: lib_fclean clean
	@rm -f $(NAME)

re: fclean all

lib_all:
	@make -C $(LIB_PATH) all
lib_clean:
	@make -C $(LIB_PATH) clean

lib_fclean: lib_clean
	@make -C $(LIB_PATH) fclean
