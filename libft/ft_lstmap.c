/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 03:56:03 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/16 03:04:21 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*x;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		x = ft_lstnew(f(lst->content));
		if (!x)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&new, x);
		lst = lst->next;
	}
	return (new);
}
