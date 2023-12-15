/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:42:25 by cyril             #+#    #+#             */
/*   Updated: 2023/12/15 09:46:45 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

/*** Still to do: (1) fix return value, (2) Error handling if error*/

static ssize_t	ft_handle_options(char c, va_list args)
{
	ssize_t	_len;

	_len = 0;
	if (c == 'c')
		_len = ft_putchar_fd((char)va_arg(args, int), 1);
	else if (c == 's')
		_len = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'd' || c == 'i')
		_len = ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		_len = ft_putnb_b_fd(va_arg(args, unsigned int), BASE_10, 1);
	else if (c == 'x')
		_len = ft_putnb_b_fd(va_arg(args, unsigned int), BASE_16_LO, 1);
	else if (c == 'X')
		_len = ft_putnb_b_fd(va_arg(args, unsigned int), BASE_16_UP, 1);
	else if (c == 'p')
		_len = ft_putptr_fd(va_arg(args, void *), 1);
	else if (c == '%')
		_len = ft_putchar_fd('%', 1);
	return (_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	len_written;
	ssize_t	result;

	len_written = 0;
	result = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			result = write(1, format, 1);
			format++;
		}
		else if (*format++)
		{
			result = ft_handle_options(*format, args);
			format++;
		}
		if (result == -1)
			return (-1);
		len_written += result;
	}
	return ((int)(len_written));
}
