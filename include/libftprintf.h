#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# define BASE_10 "0123456789"
# define BASE_16_UP "0123456789ABCDEF"
# define BASE_16_LO "0123456789abcdef"

# include <unistd.h>
# include <stdlib.h>


typedef enum bool {
	FALSE, TRUE
} bool;

int	ft_printf(const char *format, ...);
char	*ft_conv_base(int number, char *base);
ssize_t ft_putptr_fd(void *ptr, int fd);
ssize_t	ft_putptr_fd(void *addr, int fd);
ssize_t	ft_putnbrbase_fd(unsigned int number, char *base, int fd);

#endif