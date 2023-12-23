/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:23:26 by claferri          #+#    #+#             */
/*   Updated: 2023/11/13 12:14:46 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
/*
The strnstr() function locates the first occurrence of the null-terminated 
string little in the string big, where not more than len chars are searched.
If little is an empty string, big is returned; if little occurs nowhere in big,
NULL is returned; otherwise a pointer to the first character of the first occurrence
of little is returned.
*/
{
	size_t	len_little;

	if (!*little)
		return ((char *)big);
	len_little = ft_strlen(little);
	while (*big && len >= len_little)
	{
		if (!ft_strncmp(big, little, len_little))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
