/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:44:23 by cyril             #+#    #+#             */
/*   Updated: 2023/11/28 21:03:58 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst && new)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

/*
int	main()
{
	t_list *test0 = ft_lstnew((void *)("test0"));
	t_list *test1 = ft_lstnew((void *)("test1"));
	t_list *test2 = ft_lstnew((void *)("test2"));
	test0->next = test1;
	ft_lstadd_back(&test0, test2);
	char * result = (char *)(test0->next->next->content);
}
*/
