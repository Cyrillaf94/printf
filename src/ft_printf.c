#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	ssize_t len_written;

	len_written = 0;
	va_start(args, format);
	while (format)
	{
		if (*format != '%')
			len_written += write(1, format, 1);
		else
		{
			if (*format++)
			{
				if (*format == 'c')
					len_written += ft_putchar_fd((char)va_arg(args, int), 1);
				if (*format == 's')
					len_written += ft_putstr_fd(va_arg(args, char*), 1);
				if (*format == 'd' || *format == 'i')
					len_written += ft_putnbr_fd(va_arg(args, int), 1);
				if (*format == '%')
					len_written += ft_putchar_fd('%', 1);
				format++;
			}
		}
	}
	return (len_written);
}