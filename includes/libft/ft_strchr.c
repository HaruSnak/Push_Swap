/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:17:50 by shmoreno          #+#    #+#             */
/*   Updated: 2023/10/23 13:17:50 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}
/*
int	main(void)
{
	//char caractere = 'j';
	//char *chaine = "Bonjour, je suis une chevret";
	printf("%s", ft_strchr("teste", '\0'));
	return (0);
}*/