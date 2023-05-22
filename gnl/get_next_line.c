/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:45:37 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/03/15 11:27:58 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *) malloc (i + 2);
	while (j <= i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_the_remainder(char *str)
{
	char	*rem;
	int		i;

	i = 0;
	rem = 0;
	if (!str)
	{
		free (str);
		return (0);
	}
	while (str[i] != '\n' && str[i])
		i++;
	if (gnl_strchr(str, '\n'))
		rem = gnl_strdup(str + i + 1);
	free (str);
	return (rem);
}

char	*reading(int fd, char *str)
{
	char	*buff;
	int		rd;

	rd = 1;
	buff = 0;
	while ((gnl_strchr(str, '\n') == 0 && rd > 0))
	{
		buff = (char *)malloc(BUFFER_SIZE + 1);
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free (buff);
			return (0);
		}
		buff[rd] = '\0';
		str = gnl_strjoin(str, buff);
		free (buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str = reading(fd, str);
	if (!str)
		return (0);
	line = get_the_line(str);
	str = get_the_remainder(str);
	return (line);
}
