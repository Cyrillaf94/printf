/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_b_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:29:19 by cyril             #+#    #+#             */
/*   Updated: 2023/12/23 17:24:29 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

ssize_t	ft_putnb_b_fd(unsigned int number, char *base, int fd)
{
	size_t	len_base;
	ssize_t	len_floor;
	ssize_t	len_mod;

	len_base = ft_strlen(base);
	if (number >= len_base)
	{
		len_floor = ft_putnb_b_fd((unsigned int)(number / len_base), base, fd);
		if (len_floor == -1)
			return (-1);
		len_mod = ft_putnb_b_fd((unsigned int)(number % len_base), base, fd);
		if (len_mod == -1)
			return (-1);
		return (len_floor + len_mod);
	}
	else
		return (ft_putchar_fd_st(base[number], fd));
}
