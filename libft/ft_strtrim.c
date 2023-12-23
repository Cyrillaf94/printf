/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:44:51 by claferri          #+#    #+#             */
/*   Updated: 2023/11/24 15:12:15 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trim;

	if (*set)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
		len = ft_strlen(s1);
		while (len && ft_strchr(set, *(s1 + len - 1)))
			len--;
	}
	else
		len = ft_strlen(s1);
	trim = ft_strndup(s1, len);
	return (trim);
}
