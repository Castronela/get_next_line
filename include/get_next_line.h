/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:17:36 by dstinghe          #+#    #+#             */
/*   Updated: 2025/02/25 00:13:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_FDS 4096

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ========================= Function declarations ========================= */

char	*get_next_line(int fd);

/* --------------------------------- Utils --------------------------------- */

int		read_file(int fd, char *buffer, char *line);
int		process_line(char *buffer, char **line, size_t end_index);

#endif