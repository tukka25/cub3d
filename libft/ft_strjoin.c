/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:52:47 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/23 16:29:33 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a new string, which is the result of
the concatenation of ’s1’ and ’s2’.*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*joint;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	joint = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joint == 0)
		return (0);
	while (s1[i])
		joint[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joint[j++] = s2[i++];
	joint[j] = '\0';
	return (joint);
}
