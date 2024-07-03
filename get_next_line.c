/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:17:50 by dstinghe          #+#    #+#             */
/*   Updated: 2024/04/23 02:25:58 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	int			bytes_read;

	line = NULL;
	buff = realloc_mem(buff, BUFFER_SIZE);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		if (read_file(fd, &buff, &bytes_read) == ERROR)
		{
			if (line)
				free(line);
			return (NULL);
		}
		if (process_line(&buff, &line, &bytes_read) == ERROR)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
	}
	return (line);
}
