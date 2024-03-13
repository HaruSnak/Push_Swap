/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_primary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:54:11 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/17 15:42:40 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int	ft_conv_string(va_list ap)
{
	char	*str;
	size_t	i;

	i = 0;
	str = va_arg(ap, char *);
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_conv_pointer(va_list ap)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putnbr_base((unsigned long long)ptr, "0123456789abcdef") + 2);
}

int	ft_conv_percent(void)
{
	char	c;

	c = '%';
	return (write(1, &c, 1));
}

int	ft_conv_unsigned(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789"));
}
