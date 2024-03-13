/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:41:57 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/02 17:54:47 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countnumber(int n)
{
	size_t	count_n;

	count_n = 0;
	if (n < 0)
	{
		n = n * (-1);
		count_n = 1;
	}
	if (n == 0)
		count_n = 1;
	else
	{
		while (n != 0)
		{
			n = n / 10;
			count_n++;
		}
	}
	return (count_n);
}

char	*ft_itoa(int n)
{
	size_t	length;
	size_t	is_negative;
	long	nb;
	char	*ptr;

	length = ft_countnumber(n);
	is_negative = 0;
	nb = (long) n;
	ptr = malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (NULL);
	if (nb < 0)
	{
		nb = nb * (-1);
		ptr[0] = '-';
		is_negative = 1;
	}
	ptr[length] = '\0';
	while (length > is_negative)
	{
		ptr[length - 1] = nb % 10 + '0';
		nb = nb / 10;
		length--;
	}
	return (ptr);
}
/*
int	main(void)
{
	//int		num;
	char	*str;

	//num = 1;
	str = ft_itoa(-2147483648);
	printf("La chaine de caracteres est : %s\n", str);
	free(str);
	return (0);
}*/