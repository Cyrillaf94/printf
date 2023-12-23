/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:38:39 by claferri          #+#    #+#             */
/*   Updated: 2023/11/15 07:57:09 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*num;
	size_t	len;
	int		cpy;

	len = 0;
	cpy = n;
	while (cpy && ++len)
		cpy /= 10;
	if (n <= 0)
		len++;
	num = ft_calloc(len + 1, sizeof(char));
	if (!num)
		return (NULL);
	if (n < 0)
		num[0] = '-';
	if (!n)
		num[0] = '0';
	while (n)
	{
		num[--len] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	return (num);
}

/*
int	main()
{
	char *test0 = ft_itoa(0);
	char *test1 = ft_itoa(10101010);
	char *test2 = ft_itoa(316484351);
	char *test3 = ft_itoa(-2587);
	return 0;
}
*/
