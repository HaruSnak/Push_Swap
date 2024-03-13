/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:16:50 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/03 15:54:37 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(s + i) = (unsigned char) c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	//char str[50] = "Hello, world!";
	//printf("Avant memset : %s\n", str);

	//ft_memset(((void*)0), '0', 5); // Remplir les 5 premiers caractères avec 'A'

	printf("Après memset : %s\n", ft_memset(((void*)0), 'a', 12));

	return (0);
}*/