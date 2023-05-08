/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:02:59 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/08 01:17:57 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				c;
	int				k;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	i = 0;
	c = ft_strlen(s1) - 1;
	k = ft_strlen(s2) - 1;
	while (i < n && c >= 0 && k >= 0)
	{
		if (ns1[c] != ns2[k])
			return (ns1[c] - ns2[k]);
		i++;
		c--;
		k--;
	}
	if (i != n)
		return (ns1[c] - ns2[k]);
	return (0);
}
