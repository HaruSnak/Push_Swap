/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:32:14 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/03 16:22:00 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_search_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*ptr;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && ft_search_set(s1[start], set))
		start++;
	while (start < end && ft_search_set(s1[end - 1], set))
		end--;
	ptr = malloc(sizeof(*s1) * (end - start + 1));
	if (!ptr)
		return (NULL);
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char example[] = "   Hello, World!   ";
	char chars_to_remove[] = " \t\n";

	printf("Avant strtrim: \"%s\"\n", example);
	printf("Chars to remove: \"%s\"\n", chars_to_remove);

	char *result = ft_strtrim(example, chars_to_remove);

	if (result != NULL)
	{
		printf("Après strtrim: \"%s\"\n", result);
		free(result);
	}
	else
	{
		printf("Une erreur s'est produite lors de l'exécution de strtrim.\n");
	}
	return (0);
}*/