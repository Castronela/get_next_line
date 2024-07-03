/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:17:36 by dstinghe          #+#    #+#             */
/*   Updated: 2024/04/23 02:25:53 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		str_len(char *str);
void	str_cpy(char *dst, char *src, int size);
char	*realloc_mem(char *ptr, int new_size);
int		process_line(char **buff, char **line, int *bytes_read);
int		read_file(int fd, char **buff, int *bytes_read);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ERROR -1

#endif