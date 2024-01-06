/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_st.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:06:24 by cyril             #+#    #+#             */
/*   Updated: 2024/01/06 09:30:32 by claferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libftprintf.h"

ssize_t	ft_putnbr_fd_st(int n, int fd)
{
	char	*num;
	ssize_t	result;

	num = ft_itoa(n);
	if (num)
	{
		result = ft_putstr_fd_st(num, fd);
		free(num);
		return (result);
	}
	return (-1);
}
