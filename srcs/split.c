/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:51:23 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:30:33 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c && in_word)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	**allocate_words(const char *s, char c, int count, char *c_str)
{
	char	**result;
	int		i;

	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		result[i] = ft_strndup(s, strcspn(s, c_str));
		if (!result[i])
		{
			while (i >= 0)
				free(result[i--]);
			free(result);
			return (NULL);
		}
		s += strcspn(s, c_str);
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;
	char	c_str[2];

	if (!s)
		return (NULL);
	c_str[0] = c;
	c_str[1] = '\0';
	count = word_count(s, c);
	result = allocate_words(s, c, count, c_str);
	return (result);
}
