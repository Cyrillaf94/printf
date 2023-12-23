/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:42:17 by claferri          #+#    #+#             */
/*   Updated: 2023/11/06 21:08:00 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*_src;
	unsigned char	*_dest;

	_src = (unsigned char *)src;
	_dest = (unsigned char *)dest;
	if (_dest < _src || _dest >= _src + n)
	{
		while (n--)
			*_dest++ = *_src++;
	}
	else
	{
		while (n--)
			*(_dest + n) = *(_src + n);
	}
	return (dest);
}

/*
int main() {
    char buffer[] = "Hello, World!";
	
    printf("Before memmove: %s\n", buffer);
    ft_memmove(buffer, buffer + 6, 10);
    printf("After memmove:  %s\n", buffer);

    return 0;
}
*/
