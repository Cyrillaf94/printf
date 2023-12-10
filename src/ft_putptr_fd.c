/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:37:10 by cyril             #+#    #+#             */
/*   Updated: 2023/12/10 18:17:17 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "libftprintf.h"

static ssize_t ft_putptr_addr_fd(uintptr_t address, int fd)
{
	ssize_t	len_written;
	ssize_t result;

	len_written = 0;
	if (address >= 16)
	{
		ft_putptr_addr_fd(address / 16, fd);
		result = ft_putptr_addr_fd(address % 16, fd);
		if (result == -1)
			return (-1);
		len_written += result;
	}
	else
	{
		result = ft_putchar_fd(BASE_16_LO[address % 16], fd);
		if (result == -1)
			return (-1);
		len_written += result;
	}
	return (len_written);
}

ssize_t	ft_putptr_fd(void *ptr, int fd)
{
	uintptr_t	address;
	ssize_t		len_w;
	ssize_t		result;

	if (!ptr)
		return (write(fd, "(nil)", 5));
	address = (uintptr_t)ptr;
	len_w = write(1, "0x", 2);
	if (len_w > -1)
		result = ft_putptr_addr_fd(address, fd);
	if (result == -1)
		return (-1);
	return (result + len_w);
}

