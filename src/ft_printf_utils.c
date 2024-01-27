/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:29:19 by cyril             #+#    #+#             */
/*   Updated: 2024/01/27 16:18:49 by claferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	const char	*str_2;

	str_2 = str;
	while (*str)
		str++;
	return (str - str_2);
}

ssize_t	ft_putnb_u_b_fd(t_ull number, char *base, int fd)
{
	size_t	len_base;
	ssize_t	len_floor;
	ssize_t	len_mod;

	len_base = ft_strlen(base);
	if (number >= len_base)
	{
		len_floor = ft_putnb_b_fd(number / len_base, base, fd);
		len_mod = ft_putnb_b_fd(number % len_base, base, fd);
		return (len_floor + len_mod);
	}
	else
		return (write(fd, &base[number], 1));
}

ssize_t	ft_putnb_b_fd(t_ll number, char *base, int fd)
{
	ssize_t	sign;

	sign = 0;
	if (number < 0)
	{
		sign = write(fd, "-", 1);
		number = (t_ull)(-number);
	}
	return (sign + ft_putnb_u_b_fd((t_ull)number, base, fd));
}

ssize_t	ft_putptr_fd(void *ptr, int fd)
{
	if (!ptr)
		return (write(fd, "(nil)", 5));
	return (write(fd, "0x", 2) + ft_putnb_u_b_fd((t_ull) ptr, BASE_16_LO, fd));
}

ssize_t	ft_putstr_fd_st(char *s, int fd)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		return (write(fd, s, len));
	}
	else
		return (write(fd, "(null)", 6));
}
