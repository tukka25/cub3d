/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:04:03 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/20 20:05:06 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*new_s;

	new_s = (char *)s;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == (char)c)
		{
			return (new_s + i);
		}
		i++;
	}
	return (NULL);
}
