/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:07:10 by feralves          #+#    #+#             */
/*   Updated: 2022/08/02 22:01:59 by feralves         ###   ########.fr       */
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


size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
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

char    *write_rest(char **rest)
{
    char *dest;
 	char *temp;
    size_t index;
    size_t size;
	ssize_t	buffer; //ssize_t - aceita sinal
	
    index = 0;
    size = 0;
    size = ft_strlen_mod(*rest, '\0', index); //defining temp as *rest
    temp = malloc((size + 1) * sizeof(char));
    if (!temp)
        return (MALLOC_ERROR);
    temp[size] = '\0';
    printf("TEMP[rest] %s\n", temp);
    ft_strlcpy_mod(temp, *rest, '\0', index);
    size = ft_strlen_mod(temp, '\n', index); //size for writing
    dest = malloc((size + 2) *  sizeof(char));
    if (!dest)
        return (MALLOC_ERROR);
    ft_strlcpy_mod(dest, temp, '\n', index);
    printf("DEST[rest]:\n%s\n", dest);
    index = size;
    if (temp[index] != '\0')
    {
        size = ft_strlen_mod(temp, '\0', index);
		*rest = malloc((size + 1) * sizeof(char));
        if (!*rest)
            return (MALLOC_ERROR);
        ft_strlcpy_mod(*rest, temp, '\0', index + 1);
    }
    dest[index] = '\n'; //adicionar um enter a mais na saída do dest
    index++;
    dest[index] = '\0'; //finalizar string
    return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	dest = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	while (s1 && s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	while (s2[index] != '\0')
	{
		dest[count + index] = s2[index];
		index++;
	}
	dest[count + index] = '\0';
	return (dest);
}


char    *ft_read(int fd, char **rest)
{
    char    *temp;
    char    *new;
    ssize_t buffer;
	int	index;

    temp = NULL;
	index = 0;
    new = malloc((BUFFER_SIZE + 1) * sizeof(char)); //free no new?
    if (!new)
        return (MALLOC_ERROR);
    buffer = read(fd, new, BUFFER_SIZE);
	while (new[index] != '\n')
	{
		index++;
	}
	if (new[index] == '\n')
	{
		index = 0;
		new[buffer] = '\0';
		ft_strlcpy_mod(temp, new, '\0', index);
		temp[buffer] = '\0';
	}
	else
	{
		new[buffer] = '\0';
		temp = ft_strjoin(temp, new);
		buffer = read(fd, new, BUFFER_SIZE);		
	}
/*     while (buffer > 0)
    {

    } */
    return (temp);

}

char    *get_first_line(int fd, char **rest)
{
    char *dest;
 	char *temp;
    size_t index;
    size_t size; //trocar por len
	int	buffer; //ssize_t - aceita sinal
	
    index = 0;
    size = 0;
    temp = ft_read(fd, rest); //read txt
    printf("TEMP:\n%s\n", temp); //tester temp
	size = ft_strlen_mod(temp, '\n', index);
    dest = malloc((size + 2) *  sizeof(char));
    if (!dest)
        return (MALLOC_ERROR);
    ft_strlcpy_mod(dest, temp, '\n', index);
    printf("DEST:\n%s\n", dest);
    index = size;
    if (temp[index] != '\0')
    {
        size = ft_strlen_mod(temp, '\0', index);
		*rest = malloc((size + 1) * sizeof(char));
        if (!*rest)
            return (MALLOC_ERROR);
        ft_strlcpy_mod(*rest, temp, '\0', index + 1);
    }
    printf("REST:\n%s\n\n", *rest); //tester rest
    dest[index] = '\n'; //adicionar um enter a mais na saída do dest
    index++;
    dest[index] = '\0'; //finalizar string
    return (dest);
}

char    *get_next_line(int fd)
{
    static char  *rest;
    char *dest;
    
    //verificações de erro
    //fd < 0/
     if (rest)
        dest = write_rest(&rest);
    else
        dest = get_first_line(fd, &rest);
    return (dest);
}