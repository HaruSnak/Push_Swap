/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:58:24 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/03 15:53:29 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			*(unsigned char *)(s + i) = 0;
			i++;
		}
	}
}
/*
int	main(void)
{
	char test_string[20] = "Hello, world!";
	printf("Avant ft_bzero : %s\n", test_string);

	ft_bzero(test_string, 5); // Initialiser les 5 premiers octets à zéro

	printf("Après ft_bzero : %s\n", test_string);

	return (0);
}*/