/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:24:04 by shmoreno          #+#    #+#             */
/*   Updated: 2023/10/23 13:24:04 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int size)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && size != 0)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		size--;
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	//char *chaine = "axexxx";
	//char *caractere = "axxxxx";
	printf("%d", ft_strncmp("abcdef", "abc\375xx", 5));
	return (0);
}*/