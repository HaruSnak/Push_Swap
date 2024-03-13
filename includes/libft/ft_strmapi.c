/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:23:52 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/03 16:23:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
char	add_index(unsigned int index, char c) {
	return (c + index); // Incrémente chaque caractère par son index
}

int	main(void) {
	const char *test_string = "abcd";
	printf("Chaîne initiale : %s\n", test_string);

	char *result_string = ft_strmapi(test_string, &add_index);

	if (result_string) {
		printf("Résultat de strmapi : %s\n", result_string);
		free(result_string); // Libérer la mémoire allouée dynamiquement
	} else {
		printf("Une erreur s'est produite lors de l'exécution de strmapi.\n");
	}

	return (0);
}*/