/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:15:46 by shmoreno          #+#    #+#             */
/*   Updated: 2024/02/23 18:58:03 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conditions(char c, va_list condit)
{
	if (c == 'c')
		return (ft_conv_char(condit));
	else if (c == 's')
		return (ft_conv_string(condit));
	else if (c == '%')
		return (ft_conv_percent());
	else if (c == 'u')
		return (ft_conv_unsigned(condit));
	else if (c == 'd' || c == 'i')
		return (ft_conv_decimal(condit));
	else if (c == 'x')
		return (ft_conv_hexa_low(condit));
	else if (c == 'X')
		return (ft_conv_hexa_upper(condit));
	return (write(1, &c, 1));
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	args;
	size_t	count;

	if (!format)
		return (0);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && (!format[i + 1]))
			break ;
		else if (format[i] == '%')
		{
			i++;
			count += ft_conditions(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{

	ft_printf("Bonjour, je suis une frite %d ! 1658", 150);
	return (0);
}*/
//Bonjour, je suis une frite 150 ! 1658