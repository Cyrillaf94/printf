/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:19:03 by claferri          #+#    #+#             */
/*   Updated: 2023/11/15 07:58:14 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**ft_clear_mem(char **err)
{
	if (err)
	{
		while (*err)
		{
			free (*err);
			*err++ = NULL;
		}
		free (err);
		err = NULL;
	}
	return (err);
}

static size_t	ft_n_words(char const *s, char c)
{
	size_t	n_words;
	int		i;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n_words++;
		i++;
	}
	return (n_words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*str_end;
	int		i;
	int		index;

	i = 0;
	index = 0;
	split = (char **) ft_calloc(ft_n_words(s, c) + 1, sizeof(char *));
	while (split && s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			str_end = ft_strchr(s + i, c);
			if (str_end)
				split[index] = ft_strndup(s + i, (size_t)(str_end - (s + i)));
			else
				split[index] = ft_strdup(s + i);
			if (!split[index])
				split = (char **) ft_clear_mem(split);
			index++;
		}
		i++;
	}
	return (split);
}

/*
int	main()
{
	char **test0 = ft_split("aaaasjhdbjfbsfbsfbsfweoooo", 'o');
	char **test1 = ft_split("ooooaaaasjhdbjfbsfbsfbsfwe", 'o');
	char **test2 = ft_split("aaaasjhdbjfbsfbsfbsfwe", 'o');
	return (0);
}
*/
