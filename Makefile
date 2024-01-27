NAME := libftprintf.a
HEADER_FOLDER := include
SRC := 	src/ft_printf.c src/ft_printf_utils.c
OBJ := 	obj/ft_printf.o obj/ft_printf_utils.o
CC := cc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_FOLDER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all