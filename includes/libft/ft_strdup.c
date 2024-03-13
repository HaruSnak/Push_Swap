/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:18:12 by shmoreno          #+#    #+#             */
/*   Updated: 2023/10/23 13:18:12 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void) {
	char *original = "Bonjour, le monde !";
	char *copie = ft_strdup(original);

	if (copie) {
		printf("Chaine originale : %s\n", original);
		printf("Copie : %s\n", copie);
		free(copie);
	} else {
		printf("Échec de l'allocation mémoire.\n");
	}

	return (0);
}*/