/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:24:46 by dstinghe          #+#    #+#             */
/*   Updated: 2024/04/23 02:37:02 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buff[4096];
	char		*line;
	int			bytes_read;

	line = NULL;
	if (fd < 0)
		return (NULL);
	buff[fd] = realloc_mem(buff[fd], BUFFER_SIZE);
	if (!buff[fd])
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		if (read_file(fd, &buff[fd], &bytes_read) == ERROR)
		{
			if (line)
				free(line);
			return (NULL);
		}
		if (process_line(&buff[fd], &line, &bytes_read) == ERROR)
			return (free(buff[fd]), buff[fd] = NULL, NULL);
	}
	return (line);
}
