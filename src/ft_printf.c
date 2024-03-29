/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:42:25 by cyril             #+#    #+#             */
/*   Updated: 2024/01/27 16:15:28 by claferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static ssize_t	ft_handle_options(char c, va_list args)
{
	ssize_t	_len;
	int		arg_char;

	_len = 0;
	if (c == 'c')
	{
		arg_char = va_arg(args, int);
		_len = write(1, &arg_char, 1);
	}
	else if (c == 's')
		_len = ft_putstr_fd_st(va_arg(args, char *), 1);
	else if (c == 'd' || c == 'i')
		_len = ft_putnb_b_fd((t_ll)va_arg(args, int), BASE_10, 1);
	else if (c == 'u')
		_len = ft_putnb_b_fd((t_ll)va_arg(args, unsigned int), BASE_10, 1);
	else if (c == 'x')
		_len = ft_putnb_u_b_fd((t_ll)va_arg(args, unsigned int), BASE_16_LO, 1);
	else if (c == 'X')
		_len = ft_putnb_u_b_fd((t_ll)va_arg(args, unsigned int), BASE_16_UP, 1);
	else if (c == 'p')
		_len = ft_putptr_fd(va_arg(args, void *), 1);
	else if (c == '%')
		_len = write(1, "%", 1);
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
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format != '%')
			result = write(1, format++, 1);
		else if (*++format)
			result = ft_handle_options(*format++, args);
		len_written += result;
	}
	va_end(args);
	return ((int)(len_written));
}
