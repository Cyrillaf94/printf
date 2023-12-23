/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:04:14 by cyril             #+#    #+#             */
/*   Updated: 2023/11/28 21:04:12 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
int	main()
{
	t_list test0;
	t_list test1;
	t_list *test3 = &test0;
	test0.content = "test0";
	test1.content = "test1";
	ft_lstadd_front(&test3, &test1);
	char * result = (char *)(test3->content);
}
*/
