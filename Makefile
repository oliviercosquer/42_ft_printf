NAME = ft_printf
INCLUDE_PATH = -I./include/
SRC_PATH = ./src/
SRC_FILES =	main.c ft_printf.c ft_printf_str.c \
			ft_type.c ft_int.c ft_params_check.c
BASE_FILES = $(addprefix $(SRC_PATH),$(SRC_FILES))
SRC = $(BASE_FILES)

all: ${NAME}

${NAME}:
	@echo compilation of $(NAME)
	gcc $(OPTI) $(INCLUDE_PATH) -Wall -Werror -Wextra $(SRC) -o $(NAME)
	@echo Compilation done!

clean:
	@echo Delete .o files
	@rm -f $(SRC_FILES:.c=.o)
	@echo Delete done!

fclean: clean
	@echo Delete $(NAME)
	@rm -f $(NAME)
	@echo Delete done!

re: fclean all