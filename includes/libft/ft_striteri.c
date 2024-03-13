/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:18:59 by shmoreno          #+#    #+#             */
/*   Updated: 2023/10/23 13:19:01 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	print_char(unsigned int index, char *c) {
	printf("Character at index %d: %c\n", index, *c);
		// Afficher le caractère et son index
}

int	main(void) {
	char test_string[] = "example";
	printf("Chaîne initiale : %s\n", test_string);

	ft_striteri(test_string, &print_char);
		// Appliquer ft_striteri avec la fonction print_char

	return (0);
}*/