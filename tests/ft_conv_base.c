/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:00:19 by cyril             #+#    #+#             */
/*   Updated: 2023/12/10 17:17:39 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*** Get a int and return it in base provided with a freeable string
	if allocation error occurs, a NULL pointer is returned
  ****/

#include "libft.h"
#include "libftprintf.h"

static size_t	ft_len_conv_base(int number, char *base)
{
	size_t	len_base;
	size_t	len_conv;

	len_base = ft_strlen(base);
	len_conv = 0;
	if (number < 0)
		len_conv++;
	while (number)
	{
		number /= len_base;
		len_conv++;
	}
	return (len_conv);
}

bool	ft_is_valid_base(char *base)
/**** Base is invalid if:
 * 			- (1) base is NULL
 * 			- (2) len < 2, 
 * 			- (3) characters are non printable, 
 * 			- (4) characters are present more than once****/
{
	if (!base)
		return (FALSE);
	if (ft_strlen(base) < 2)
		return (FALSE);
	while (*base)
	{
		if (ft_strchr(base + 1, (int)(*base)))
			return (FALSE);
		if (!ft_isascii(*base))
			return (FALSE);
		base++;
	}
	return (TRUE);
}

char	*ft_conv_base(int number, char *base)
{
	size_t	len_base;
	size_t	len_conv;
	char	*conv_base;

	if (!ft_is_valid_base(base))
		return (ft_strdup(""));
	if (number == 0)
		return (ft_strndup(base, 1));
	len_conv = ft_len_conv_base(number, base);
	conv_base = ft_calloc(len_conv + 1, sizeof(char));
	if (!conv_base)
		return (NULL);
	if (number < 0)
		conv_base[0] = '-';
	number = ft_abs(number);
	len_base = ft_strlen(base);
	while (number)
	{
		conv_base[--len_conv] = base[number % len_base];
		number /= len_base;
	}
	return (conv_base);
}
