NAME := libftprintf.a
HEADER_FOLDER := include
SRC := 	src/ft_printf.c src/ft_putnb_b_fd.c src/ft_putptr_fd.c
OBJ := 	obj/ft_printf.o obj/ft_putnb_b_fd.o obj/ft_putptr_fd.o
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