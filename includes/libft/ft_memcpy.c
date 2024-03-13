/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:16:29 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/03 16:38:54 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src[50] = "Bonjour";
	char dest[50];

	printf("Avant memcpy, dest : %s\n", dest);

	ft_memcpy(dest, src, ft_strlen(src) + 1); // Copie de src vers dest

	printf("Après memcpy, dest : %s\n", dest);

	return (0);
}*/