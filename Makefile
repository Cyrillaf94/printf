NAME := libft.a
HEADER_FOLDER := include
SRC := 	ft_printf.c ft_putnbr_fd.c ft_putptr.c
OBJ := 	ft_printf.o ft_putnbr_fd.o ft_putptr.o
CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBS := ft

all: $(NAME)

bonus : $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all