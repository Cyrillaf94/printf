/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:39:41 by claferri          #+#    #+#             */
/*   Updated: 2023/11/22 21:19:49 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *bigptr, int ch, size_t length)
{
	char	*p;
	char	c;

	if (!bigptr)
		return (NULL);
	p = (char *)bigptr;
	c = (char)ch;
	while (length--)
	{
		if (*p == c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
