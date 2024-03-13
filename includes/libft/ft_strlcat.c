/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:19:22 by shmoreno          #+#    #+#             */
/*   Updated: 2023/11/01 17:19:24 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;

	dst_len = ft_strlen(dest);
	index = 0;
	while (dest[index])
		index++;
	i = 0;
	while (src[i] && (i + index + 1) < (size))
	{
		dest[index + i] = src[i];
		i++;
	}
	if (i < size)
		dest[index + i] = '\0';
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + dst_len);
}
/*
int	main(void)
{
	//char *source = 0;
	//char destination[20] = "Hello, ";

	printf("%ld", ft_strlcat("pqrstuvwxyz", "abcd", 2));
}*/