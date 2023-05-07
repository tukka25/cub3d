/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:10:11 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/20 20:03:35 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	tmp;

	tmp = (char ) c;
	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == tmp)
			return ((char *)&s[n]);
		n--;
	}
	return (NULL);
}
