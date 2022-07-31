/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:07:10 by feralves          #+#    #+#             */
/*   Updated: 2022/07/31 04:29:21 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_mod(const char *str, char a, size_t count)
{
	size_t  size;

    size = 0;
    while (str[count] != a)
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
	while (src[index] != a)
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
	int	buffer; //ssize_t - aceita sinal
	
    index = 0;
    size = 0;
    //verificações de erro
    //fd < 0/
    printf("1st test[rest]:\nindex %ld size %ld\n", index, size); //tester ints
    size = ft_strlen_mod(*rest, '\0', index); //defining temp as *rest
    printf("2nd test[rest]:\nindex %ld size %ld\n", index, size); //tester ints
    temp = malloc((size + 1) * sizeof(char));
    if (!temp)
        return (MALLOC_ERROR);
    temp[size] = '\0';
    printf("TEMP[rest] %s\n", temp);
    ft_strlcpy_mod(temp, *rest, '\0', index);
    size = ft_strlen_mod(temp, '\n', index); //size for writing
    printf("3rd test[rest]:\nindex %ld size %ld\n", index, size); //tester ints
    dest = malloc((size + 2) *  sizeof(char));
    if (!dest)
        return (MALLOC_ERROR);
    ft_strlcpy_mod(dest, temp, '\n', index);
    printf("DEST[rest]:\n%s\n", dest);
    index = size;
    printf("4th test[rest]:\nindex %ld size %ld\n", index, size); //tester ints
    if (temp[index] != '\0')
    {
        size = ft_strlen_mod(temp, '\0', index);
        printf("5th test[rest]:\nindex %ld size %ld\n", index, size); //tester ints
		*rest = malloc((size + 1) * sizeof(char));
        if (!*rest)
            return (MALLOC_ERROR);
        ft_strlcpy_mod(*rest, temp, '\0', index + 1);
    }
    printf("REST[rest]:\n%s\n\n", *rest); //tester rest
    dest[index] = '\n'; //adicionar um enter a mais na saída do dest
    index++;
    dest[index] = '\0'; //finalizar string
    return (dest);
}


char    *get_first_line(int fd, char **rest)
{
    char *dest;
 	char *temp;
    size_t index;
    size_t size;
	int	buffer; //ssize_t - aceita sinal
	
    index = 0;
    size = 0;
    //verificações de erro
    //fd < 0/
 
    printf("1st test:\nindex %ld size %ld\n", index, size); //tester ints
    temp = malloc((BUFFER_SIZE + 1) * sizeof(char)); //free no temp quando finalizar pela 1a vez?
    if (!temp)
        return (MALLOC_ERROR);
    buffer = read(fd, temp, BUFFER_SIZE);
    temp[buffer] = '\0';
    printf("TEMP:\n%s\n", temp); //tester temp
    size = ft_strlen_mod(temp, '\n', index);
    printf("2nd test:\nindex %ld size %ld\n", index, size); //tester ints
    dest = malloc((size + 2) *  sizeof(char));
    if (!dest)
        return (MALLOC_ERROR);
    ft_strlcpy_mod(dest, temp, '\n', index);
    printf("DEST:\n%s\n", dest);
    index = size;
    printf("3rd test:\nindex %ld size %ld\n", index, size); //tester ints
    if (temp[index] != '\0')
    {
        size = ft_strlen_mod(temp, '\0', index);
        printf("4th test:\nindex %ld size %ld\n", index, size); //tester ints
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
    
    if (rest)
        dest = write_rest(&rest);
    else
        dest = get_first_line(fd, &rest);
    return (dest);
}