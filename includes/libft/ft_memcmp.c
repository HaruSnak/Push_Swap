/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:16:14 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/01 17:55:26 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) < *(unsigned char *)(s2 + i))
			return (-1);
		if (*(unsigned char *)(s1 + i) > *(unsigned char *)(s2 + i))
			return (1);
		i++;
	}
	return (0);
}
/*
int	main(void) {
	char str1[] = "Hella";
	char str2[] = "Hellx";
	int result;

	result = ft_memcmp(str1, str2, ft_strlen(str1));

	if (result == 0) {
		printf("Les deux chaines sont identiques.\n");
	} else if (result < 0) {
		printf("La premiere chaine est plus petite que la deuxieme.\n");
	} else {
		printf("La premiere chaine est plus grande que la deuxieme.\n");
	}

	return (0);
}
int	main(void) {

		printf("%d\n", ft_memcmp("teste", "testex", 6));
	return (0);
}*/