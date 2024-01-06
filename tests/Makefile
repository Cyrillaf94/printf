CC := cc
CFLAGS := -Wall -Wextra -Werror
LIB_DIR := ../lib
INCLUDE_DIR := include

all: test
	rm test.out

test: main.c
	cd .. && make && cp libftprintf.a lib && cp include/libftprintf.h tests/include 
	$(CC) $(CFLAGS) -g -o test.out -I $(INCLUDE_DIR) -L$(LIB_DIR) main.c -lftprintf -lft
	cd .. && make fclean
	./test.out