/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:26:12 by dstinghe          #+#    #+#             */
/*   Updated: 2024/04/23 02:37:16 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

int	read_file(int fd, char **buff, int *bytes_read)
{
	int	bytes;

	if (!(**buff))
	{
		*bytes_read = read(fd, *buff, BUFFER_SIZE);
		bytes = *bytes_read;
		if (*bytes_read <= 0)
		{
			free(*buff);
			*buff = NULL;
			if (*bytes_read < 0)
				return (ERROR);
		}
		else
			(*buff)[*bytes_read] = 0;
	}
	return (*bytes_read);
}

char	*realloc_mem(char *ptr, int new_size)
{
	char	*new_ptr;

	new_ptr = malloc((new_size + 1) * sizeof(char));
	if (!new_ptr)
	{
		if (ptr)
		{
			free(ptr);
			ptr = NULL;
		}
		return (NULL);
	}
	new_ptr[0] = 0;
	if (!ptr)
		return (new_ptr);
	str_cpy(new_ptr, ptr, new_size);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

void	str_cpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (!src)
		return ;
	while (src[i] && size)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	while (size)
	{
		dst[i++] = 0;
		size--;
	}
	dst[i] = 0;
	return ;
}

int	process_line(char **buff, char **line, int *bytes_read)
{
	int	line_len;
	int	buff_stop;

	if (*bytes_read == 0)
		return (1);
	line_len = str_len(*line);
	buff_stop = 0;
	while ((*buff)[buff_stop])
	{
		if ((*buff)[buff_stop++] == '\n')
		{
			*bytes_read = 0;
			break ;
		}
	}
	*line = realloc_mem(*line, line_len + buff_stop);
	if (!(*line))
		return (ERROR);
	str_cpy((*line) + line_len, (*buff), buff_stop);
	str_cpy(*buff, (*buff) + buff_stop, BUFFER_SIZE);
	return (1);
}
