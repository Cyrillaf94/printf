/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:50:03 by cyril             #+#    #+#             */
/*   Updated: 2023/11/28 21:04:51 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lst_addone(t_list *src, void *(*f)(void *))
{
	void	*content;
	t_list	*element;

	content = NULL;
	element = NULL;
	if (src && src->content)
	{
		content = (void *)(f(src->content));
		if (!content)
			return (NULL);
	}
	element = ft_lstnew(content);
	return (element);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*element;

	map = NULL;
	element = NULL;
	while (lst)
	{
		if (!element)
		{
			element = ft_lst_addone(lst, f);
			map = element;
		}
		else
		{
			element->next = ft_lst_addone(lst, f);
			element = element->next;
		}
		if (!element)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (map);
}

/*
static void ft_del(void * ptr)
{
	free(ptr);
}

static void *ft_upper(void * ptr)
{
	char	*str;
	
	str = (char *)ptr;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (ptr);
}

int	main()
{
	t_list *elem0 = ft_lstnew("a");
	elem0->next = ft_lstnew("b");
	elem0->next->next = ft_lstnew("c");
	elem0->next->next->next = ft_lstnew("d");
	elem0->next->next->next->next = ft_lstnew("e");
	elem0->next->next->next->next->next = ft_lstnew("f");
	t_list *map = ft_lstmap(elem0, &ft_upper, &ft_del);
	return (0);
}
*/
