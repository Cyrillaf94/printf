/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_st.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:58:37 by cyril             #+#    #+#             */
/*   Updated: 2024/01/06 09:36:43 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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
