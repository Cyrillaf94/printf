/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:37:10 by cyril             #+#    #+#             */
/*   Updated: 2023/12/23 17:23:28 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "libftprintf.h"

static ssize_t	ft_putptr_addr_fd(uintptr_t address, int fd)
{
	ssize_t	len_floor;
	ssize_t	len_mod;

	if (address >= 16)
	{
		len_floor = ft_putptr_addr_fd(address / 16, fd);
		if (len_floor == -1)
			return (-1);
		len_mod = ft_putptr_addr_fd(address % 16, fd);
		if (len_mod == -1)
			return (-1);
		return (len_mod + len_floor);
	}
	else
		return (ft_putchar_fd_st(BASE_16_LO[address % 16], fd));
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
	if (len_w == -1)
		return (-1);
	result = ft_putptr_addr_fd(address, fd);
	if (result == -1)
		return (-1);
	return (result + len_w);
}
