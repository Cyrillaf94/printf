/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:49:39 by claferri          #+#    #+#             */
/*   Updated: 2023/11/24 15:20:02 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*match;
	char		ch;

	ch = c;
	match = NULL;
	while (*str)
	{
		if (*str == ch)
			match = str;
		str++;
	}
	if (!ch)
		return ((char *)str);
	return ((char *)match);
}
