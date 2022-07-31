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

char    *write_first_line(int fd)
{
    ssize_t index;
    ssize_t len;
    ssize_t buffer;
    char    *temp;
    char    *dest;

    index = 0;
    len = 0;
    temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!temp)
        return (NULL);
    buffer = read(fd, temp, BUFFER_SIZE);
    temp[buffer] = '\0';
    size = ft_strlen_mod(temp, '\n', index);
    dest = malloc((size + 2) *  sizeof(char));
    if (!dest)
        return (MALLOC_ERROR);
    ft_strlcpy_mod(dest, temp, '\n', index);
    index = size;
    if (temp[index] != '\0')
    {
        size =
    }
}

char    *get_next_line(int fd)
{
    static char *rest;
    char *dest;

    if (rest)
        dest = write_new_line(rest);
    else if (fd)
        dest = write_first_line(fd, rest);
    else
        return (NULL);
    return (dest);
}
