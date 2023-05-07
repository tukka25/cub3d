/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:50:36 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/24 17:11:38 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	string_len(const char *s, int j, char c)
{
	j = 0;
	while (s[j])
	{
		if (s[j] != c && (s[j + 1] == c || !s[j]))
			return (j + 1);
		j++;
	}
	return (j);
}

static char	*mem_allocation_of_strings(const char *s, char c)
{
	int		i;
	int		j;
	char	*tmp;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	j = string_len(s, j, c);
	tmp = malloc((j + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		tmp[count++] = s[i++];
	}
	tmp[count] = '\0';
	return (tmp);
}

static int	count_string(const char *s, char c)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && !s[i + 1]))
			len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		len;
	int		j;

	if (!s)
		return (NULL);
	len = count_string(s, c);
	str = malloc((len + 1) * sizeof(char *));
	j = 0;
	if (!str)
		return (NULL);
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			str[j] = mem_allocation_of_strings(s, c);
			while (*s && *s != c)
				s++;
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}
