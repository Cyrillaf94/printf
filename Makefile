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

test:
	make
	cp include/libftprintf.h tests/include
	$(CC) $(CFLAGS) -g -o tests/test.out -I tests/include -Llib tests/main.c -lftprintf -lft
	./test.out


fclean: clean
	rm -f $(NAME)

re: fclean all