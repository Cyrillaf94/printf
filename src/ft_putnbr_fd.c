/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:29:19 by cyril             #+#    #+#             */
/*   Updated: 2023/12/10 18:19:24 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbrbase_fd(unsigned int number, char *base, int fd)
{
	size_t	len_base;
	ssize_t len_w;

	len_base = ft_strlen(base);
	len_w = 0;
	if (number >= len_base)
	{
		ft_putnbrbase_fd((unsigned int)(number / len_base), base, fd);
		len_w += ft_putnbrbase_fd((unsigned int)(number % len_base), base, fd);
	}
	else
	{
		len_w += ft_putchar_fd(base[number], fd);
	}
	return (len_w);
}
