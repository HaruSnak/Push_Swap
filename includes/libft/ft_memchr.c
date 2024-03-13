/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:16:02 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/03 15:58:24 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
		{
			return (s + i);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void) {
	char str[] = "Bonjour";
	char ch = 'n';
	void *ret;

	printf("Chaine de caracteres : %s\n", str);
	ret = ft_memchr(str, ch, ft_strlen(str));

	if (ret != NULL) {
		printf("Le caractere '%c' a ete trouve dans la chaine a la position
			%ld\n", ch, (char *)ret - str);
	}   else {
		printf("Le caractere '%c' n'a pas ete trouve dans la chaine\n", ch);
	}

	return (0);
}*/