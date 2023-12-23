/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:45:22 by cyril             #+#    #+#             */
/*   Updated: 2023/11/06 21:13:27 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char		*ptr;
	size_t				n_bytes;

	if (size && count > (size_t) - 1 / size)
		return (NULL);
	n_bytes = count * size;
	ptr = malloc(n_bytes);
	if (!ptr)
		return (NULL);
	while (n_bytes--)
		*ptr++ = 0;
	ptr -= count * size;
	return (ptr);
}
