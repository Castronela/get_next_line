/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:11:30 by david             #+#    #+#             */
/*   Updated: 2025/02/24 23:12:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			read_file(int fd, char *buffer, char *line);
int			process_line(char *buffer, char **line, size_t end_index);

static char	*append_to_str(char *str, char *append, size_t size);

int	read_file(int fd, char *buffer, char *line)
{
	int	bytes_read;

	bytes_read = 0;
	while (buffer[bytes_read])
		bytes_read++;
	if (bytes_read)
		return (bytes_read);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		if (line)
			free(line);
	}
	else
		buffer[bytes_read] = 0;
	return (bytes_read);
}

int	process_line(char *buffer, char **line, size_t end_index)
{
	size_t	buffer_index;

	if (end_index == 0)
		return (0);
	*line = append_to_str(*line, buffer, end_index);
	if (!*line)
		return (1);
	buffer_index = 0;
	while (end_index < BUFFER_SIZE)
		buffer[buffer_index++] = buffer[end_index++];
	buffer[buffer_index] = 0;
	return (0);
}

static char	*append_to_str(char *str, char *append, size_t size)
{
	char	*new;
	size_t	str_len;
	size_t	index;

	str_len = 0;
	while (str && str[str_len])
		str_len++;
	new = malloc(sizeof(*new) * (str_len + size + 1));
	if (new)
	{
		index = 0;
		while (str && str[index])
		{
			new[index] = str[index];
			index++;
		}
		new[index] = 0;
		while (append && *append && size--)
			new[index++] = *append++;
		new[index] = 0;
	}
	if (str)
		free(str);
	return (new);
}
