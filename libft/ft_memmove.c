/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:04:46 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/09 23:45:08 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*new_dst;
	char		*new_src;

	i = 0;
	new_dst = (char *)dst;
	new_src = (char *)src;
	if (!src && !dst)
		return (NULL);
	if (new_dst > new_src)
	{
		while (len-- > 0)
			new_dst[len] = new_src[len];
	}
	else
	{
		while (i < len)
		{
			new_dst[i] = new_src[i];
			i++;
		}
	}
	return (new_dst);
}
