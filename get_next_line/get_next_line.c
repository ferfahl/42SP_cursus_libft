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
    ft_strlcpy_mod(temp, *rest, '\0', index);
    size = ft_strlen_mod(temp, '\n', index); //size for writing
    dest = malloc((size + 2) *  sizeof(char));
    if (!dest)
        return (MALLOC_ERROR);
    ft_strlcpy_mod(dest, temp, '\n', index);
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

char    *ft_read(int fd, char **rest)
{
    char    *temp;
    char    *new;
    ssize_t buffer;
	int	index;

    temp = ft_strjoin("", *rest);
	index = 0;
    new = malloc((BUFFER_SIZE + 1) * sizeof(char)); //free no new?
    if (!new)
        return (MALLOC_ERROR);
    buffer = read(fd, new, BUFFER_SIZE);
	while (buffer > 0)
    {
        if (ft_strchr(new, '\n'))
        {
	    	new[buffer] = '\0';
	    	temp = ft_strjoin(temp, new);
            break ;
	    }
	    else
	    {
	    	new[buffer] = '\0';
	    	temp = ft_strjoin(temp, new);
	    	buffer = read(fd, new, BUFFER_SIZE);		
	    }
    }    
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
	size = ft_strlen_mod(temp, '\n', index);
    dest = malloc((size + 2) *  sizeof(char));
    if (!dest)
        return (MALLOC_ERROR);
    ft_strlcpy_mod(dest, temp, '\n', index);
    index = size;
    if (temp[index] != '\0' && BUFFER_SIZE > 1)
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

char    *get_next_line(int fd)
{
    static char  *rest;
    char *dest;
    
    //verificações de erro
    //fd < 0/
    if (rest)
        dest = write_rest(&rest);
    else 
        rest = ft_strjoin("", "");
    dest = get_first_line(fd, &rest);
    return (dest);
}