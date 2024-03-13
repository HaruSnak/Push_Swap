/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:59:22 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/18 15:59:28 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
void	ft_putstr(const char *s);
int		ft_putnbr_base(unsigned long long nb, const char *base);
int		ft_strlen(const char *str);
int		ft_conv_char(va_list ap);
int		ft_conv_string(va_list ap);
int		ft_conv_pointer(va_list cp);
int		ft_conv_percent(void);
int		ft_conv_unsigned(va_list ap);
int		ft_conv_decimal(va_list ap);
int		ft_conv_hexa_low(va_list ap);
int		ft_conv_hexa_upper(va_list ap);
int		ft_printf(const char *format, ...);

#endif