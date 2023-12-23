/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:33:05 by claferri          #+#    #+#             */
/*   Updated: 2023/11/13 12:46:14 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				atoi;

	atoi = 0;
	i = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			i++;
	}
	while (ft_isdigit(*str))
		atoi = atoi * 10 + *str++ - '0';
	if (i % 2)
		atoi *= -1;
	return (atoi);
}
