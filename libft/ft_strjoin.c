/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:52:47 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/16 03:36:02 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
