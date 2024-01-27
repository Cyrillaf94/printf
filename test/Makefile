NAME := test_printf
HEADER_FOLDER := ../include
LIBRARY_FOLDER := .
SRC := 	main.c
CC := clang
CFLAGS := -Wall -Wextra -Werror

all: run fclean

$(NAME):
	@cd .. && make && mv libftprintf.a test && make fclean
	@$(CC) $(CFLAGS) -o $(NAME) -I $(HEADER_FOLDER) -L $(LIBRARY_FOLDER) $(SRC) -lftprintf
	
run: $(NAME)
	@./$(NAME)

fclean:
	@rm -f libftprintf.a
	@rm -f $(NAME)

re: fclean all