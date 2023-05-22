/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 03:54:39 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/16 03:15:20 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*x;

	x = ft_lstlast(*lst);
	if (!lst)
		return ;
	if (!*lst)
	{
		new->next = 0;
		*lst = new;
		return ;
	}
	x->next = new;
}
