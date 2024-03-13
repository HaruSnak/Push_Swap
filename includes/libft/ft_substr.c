/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:32:36 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/03 15:21:27 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main(void) {
	//const char *original_string = "Example String for Testing";
	//unsigned int start_index = 8;
	//size_t length = 20;

	char *result = ft_substr("hola", 4294967295, 0);
	if (result == NULL) {
		printf("La sous-chaîne n'a pas pu être extraite.\n");
		return (1);
	}

	printf("La sous-chaîne extraite est : %s\n", result);

	free(result); // Libération de la mémoire allouée pour la sous-chaîne
	return (0);
}*/