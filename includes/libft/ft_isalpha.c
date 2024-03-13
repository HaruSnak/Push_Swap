/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:00:58 by shmoreno          #+#    #+#             */
/*   Updated: 2023/10/23 13:00:58 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int main() {
    char test_char = 'A';
    int result = ft_isalpha(test_char);

    if (result == 1) {
        printf("%c est une lettre alphabétique.\n", test_char);
    } else {
        printf("%c n'est pas une lettre alphabétique.\n", test_char);
    }

    return 0;
}*/