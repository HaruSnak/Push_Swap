/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:24:19 by shmoreno          #+#    #+#             */
/*   Updated: 2023/10/23 13:24:19 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[i] != '\0' && i < size)
	{
		k = 0;
		while (str[i + k] && str[i + k] == to_find[k]
			&& to_find[k] && i + k < size)
			k++;
		if (!to_find[k])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void) {
	char *haystack = "Bonjour, toujours tout le monde !";
	char *needle = "tout";
	size_t len = ft_strlen(haystack);

	char *ptr = ft_strnstr(haystack, needle, len);

	if (ptr) {
		printf("La sous-chaîne '%s' a été trouvée à l'adresse : %p\n", needle,
			ptr);
	} else {
		printf("La sous-chaîne '%s' n'a pas été trouvée dans la chaîne.\n",
			needle);
	}

	return (0);
}
int main(void)
{
	printf("%p\n", ft_strnstr("abc", "xyz", 1));
	return (0);
}*/