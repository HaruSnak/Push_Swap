/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:19:10 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/02 16:10:19 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		p;
	char	*ptr;

	i = 0;
	p = 0;
	ptr = malloc((sizeof(char)) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!s1 || !s2 || !ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[p] = s1[i];
		p++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[p] = s2[i];
		p++;
		i++;
	}
	ptr[p] = '\0';
	return (ptr);
}
/*
int	main(void) {
	//const char *s1 = "Bonjour, ";
	//const char *s2 = "comment ça va ?";

	char *result = ft_strjoin("abc", "");
	if (result) {
		printf("La chaîne concaténée est : %s\n", result);
		free(result);
			// N'oubliez pas de libérer la mémoire allouée dynamiquement
	} else {
		printf("Erreur : la fonction ft_strjoin a retourné NULL.\n");
	}

	return (0);
}*/