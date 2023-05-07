/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:13:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/12 18:09:10 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);

int		ft_putchar(char c);

int		ft_putstr(char *str);

int		ft_putnbr(int nb);

int		hexa_upper(unsigned int x);

char	*ft_itoa(int n);

char	*ft_strcpy(char *dest, char *src);

int		ft_uputnbr(unsigned int nb);

int		hexa_lower(unsigned int x);

int		check_after_percent(char s, va_list args);

int		hexa_address(unsigned long x);

int		printingaddress(unsigned long n);

#endif