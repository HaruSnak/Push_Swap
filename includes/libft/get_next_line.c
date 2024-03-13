/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:41:19 by shmoreno          #+#    #+#             */
/*   Updated: 2024/02/23 17:36:16 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
fill_buffer: Lis le fichier en utilisant read pour ensuite stocker le contenu
dans un buffer. Si read renvoie une erreur ou 0, on free le buffer et on
retourne NULL. Sinon, on retourne le buffer.

find_espace_sequence: Cherche la première occurence de \n dans le buffer. Si
on trouve, on retourne la ligne jusqu'à \n et on stocke le reste dans un
nouveau buffer. Sinon, on retourne NULL.

process_stash: On cherche la première occurence de \n dans le buffer. Si on
trouve, on retourne la ligne jusqu'à \n et on stocke le reste dans un
nouveau buffer. Sinon, on lit le fichier avec fill_buffer et on stocke le
contenu dans un nouveau buffer. On concatène le nouveau buffer avec l'ancien
et on recommence jusqu'à trouver \n. On retourne la ligne jusqu'à \n et on
stocke le reste dans un nouveau buffer. Si read renvoie une erreur ou 0, on
free le buffer et on retourne NULL. Sinon, on retourne le buffer.
get_next_line: On vérifie que les paramètres sont valides. Si oui, on
appelle process_stash. Sinon, on free le buffer et on retourne NULL.
*/
#include "libft.h"

char	*fill_buffer(int fd)
{
	char	*buffer;
	ssize_t	read_line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_line = read(fd, buffer, BUFFER_SIZE);
	if (read_line <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[read_line] = '\0';
	return (buffer);
}

char	*find_espace_sequence(char **stash_brut)
{
	char	*find_line;
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*stash_brut)[i] != '\n' && (*stash_brut)[i] != '\0')
		i++;
	if ((*stash_brut)[i] == '\n')
	{
		find_line = ft_substr(*stash_brut, 0, i + 1);
		tmp = ft_substr(*stash_brut, i + 1, ft_strlen(*stash_brut) - i);
		free(*stash_brut);
		*stash_brut = tmp;
		return (find_line);
	}
	return (NULL);
}

char	*process_stash(char **stash, int fd)
{
	char	*tmp_stash;
	char	*line_read;
	char	*line;

	line = find_espace_sequence(stash);
	if (line)
		return (line);
	line_read = fill_buffer(fd);
	if (!line_read)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		if (*line)
			return (line);
		free(line);
		return (NULL);
	}
	tmp_stash = ft_strjoin(*stash, line_read);
	free(*stash);
	*stash = tmp_stash;
	free(line_read);
	return (get_next_line(fd));
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (!stash)
		stash = ft_strdup("");
	return (process_stash(&stash, fd));
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening files\n");
		return (1);
	}
	printf("Reading from test1.txt:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
