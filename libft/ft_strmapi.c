/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:21:23 by cyril             #+#    #+#             */
/*   Updated: 2023/11/17 00:50:41 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*mapped;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	mapped = ft_calloc(len + 1, sizeof(char));
	if (!mapped)
		return (NULL);
	while (i < len)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	return (mapped);
}
