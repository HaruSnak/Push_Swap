/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:05:19 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/03 16:02:02 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;

	ptr = (void *)malloc(num_elements * element_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num_elements * element_size);
	return (ptr);
}
/*
int	main(void)
{
	int *arr;
	size_t num_elements = 10;
	size_t element_size = sizeof(int);

	arr = ft_calloc(num_elements, element_size);

	if (arr == NULL) {
		printf("L'allocation a échoué.\n");
		return (1);
	}

	// Vérification du contenu du tableau
	for (size_t i = 0; i < num_elements; i++) {
		printf("%d ", arr[i]);
			// Tous les éléments devraient être initialisés à zéro
	}
	printf("\n");

	// Libération de la mémoire allouée
	free(arr);

	return (0);
}*/