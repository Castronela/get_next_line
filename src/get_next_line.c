/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:17:50 by dstinghe          #+#    #+#             */
/*   Updated: 2025/02/25 00:13:58 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Retrieve the whole next line from a file descriptor
 *
 * @param fd file descriptor
 * @return allocated line or NULL on file-end or error
 */
char	*get_next_line(int fd)
{
	static char	buffer[MAX_FDS][BUFFER_SIZE + 1] = {0};
	char		*line;
	int			bytes_read;
	int			end_index;

	line = NULL;
	bytes_read = 1;
	while (bytes_read && fd >= 0 && fd <= MAX_FDS)
	{
		bytes_read = read_file(fd, buffer[fd], line);
		if (bytes_read < 0)
			return (NULL);
		end_index = 0;
		while (buffer[fd][end_index])
		{
			if (buffer[fd][end_index++] == '\n')
			{
				bytes_read = 0;
				break ;
			}
		}
		if (process_line(buffer[fd], &line, end_index))
			return (NULL);
	}
	return (line);
}
