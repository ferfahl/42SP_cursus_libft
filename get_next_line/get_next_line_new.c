/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:49:03 by feralves          #+#    #+#             */
/*   Updated: 2022/07/31 06:49:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_mod(const char *src, char a, size_t count)
{
	size_t  size;

    size = 0;
    while (src[count] != a && src[count] != '\0')
	{
		count++;
        size++;
	}
	return (size);
}

void	ft_strlcpy_mod(char *dest, const char *src, char a, size_t index)
{
	size_t	count;

	count = 0;
	while (src[index] != a && src[index] != '\0')
	{
		dest[count] = src[index];
        count++;
		index++;
	}
	dest[count] = 0;
}

char    *ft_read(int fd)
{
	char    *the_reader;
	char    *line_read;
	char    *temp;
	ssize_t buffer;

	the_reader = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!the_reader)
		return (NULL);
	buffer = read(fd, the_reader, BUFFER_SIZE);
	if (buffer == -1)
		return (free(the_reader), NULL);
	line_read = ft_strdup("");
	while (buffer > 0)
	{
		the_reader[buffer] = '\0';
		temp = ft_strjoin(line_read, the_reader);
		free(line_read);
		line_read = temp;
		if (ft_strchr(line_read, '\n'))
			break ;
		buffer = read(fd, the_reader, BUFFER_SIZE);
	}
	return (free(the_reader), line_read);
}

char    *ft_split_line(char *aux_temp, char **overrun)
{
	char *dest;
	size_t index;
    size_t len;
		
    index = 0;
	len = ft_strlen_mod(aux_temp, '\n', index);
    dest = malloc((len + 2) *  sizeof(char));
    if (!dest)
        return (NULL);
    ft_strlcpy_mod(dest, aux_temp, '\n', index);
    index = len;
    if (aux_temp[index] != '\0')
    {
        len = ft_strlen_mod(aux_temp, '\0', index);
		*overrun = malloc((len + 1) * sizeof(char));
        if (!*overrun)
            return (NULL);
        ft_strlcpy_mod(*overrun, aux_temp, '\0', index + 1);
		overrun[0][len] = '\0';
    }
    dest[index] = '\n';
    index++;
    dest[index] = '\0';
    return (dest);
}

char    *ft_return_line(int fd)
{
	char	*line_read;
	char	*aux_temp;
	char	*dest;
	static char	*overrun;

	if (!overrun)
		overrun = ft_strdup("");
	line_read = ft_read(fd);
	aux_temp = ft_strjoin(overrun, line_read);
	free(overrun);
	overrun = NULL;
	if (ft_strchr(aux_temp, '\n'))
		dest = ft_split_line(aux_temp, &overrun);
	else if (*aux_temp)
		return (aux_temp);
	else
		return(free(aux_temp), NULL);
	return (free(aux_temp), dest);
}

char    *get_next_line(int fd)
{
	char *dest;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dest = ft_return_line(fd);
	return (dest);
}