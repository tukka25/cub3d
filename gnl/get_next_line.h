/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 02:11:44 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/03/15 11:29:03 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     GET_NEXT_LINE_H
# define     GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# include    <unistd.h>
# include    <stdlib.h>
# include    <fcntl.h>
# include    <stdio.h>

int		gnl_strlen(char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(char *s1);
char	*get_next_line(int fd);
char	*get_the_line(char *str);
char	*get_the_remainder(char *str);
char	*reading(int fd, char *str);

#endif