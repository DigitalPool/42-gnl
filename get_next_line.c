/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 06:31:23 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/12 07:31:06 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line(char *line)
{
	if (!line)
		return (FALSE);
	return (line[ft_strlen(line) - 1] == '\n');
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*process;
	char		*line;

	line = NULL;
	process = NULL;
	while (!is_line(line) && read_line(fd, (char **) &buffer))
	{
		process = fill_the_line(buffer);
		if (!process)
			return (free(line), NULL);
		if (line)
		{
			line = ft_strcat(line, process);
			if (!line)
				return (NULL);
		}
		else
			line = process;
	}
	return (line);
}

int	read_line(int fd, char **buffer)
{
	ssize_t	read_line;

	if (!buffer[0])
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line <= 0)
			return (FALSE);
	}
	return (TRUE);
}

char	*fill_the_line(char *buffer)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = find_end_line(buffer);
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = buffer[i];
	line[i] = '\0';
	ft_shift_str(buffer, len, BUFFER_SIZE);
	return (line);
}
