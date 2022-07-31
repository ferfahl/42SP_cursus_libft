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

void   get_next_line(int fd) //char *
{
    char *dest;
    
    
    size_t index;
	char *temp;
    size_t size;
	int	buffer; //ssize_t - aceita sinal
	char *rest;
	
    index = 0;
    size = 0;
    //verificações de erro
    //fd < 0/
//	rest = calloc(1, 1);
//	temp = calloc(1, 1);
//	dest = calloc(1, 1);
/*     if (rest)
    {
    
    } */
//    printf("1st test:\n index %ld size %ld\n", index, size); //tester ints
    temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
/*     if (!temp)
        return (MALLOC_ERROR); */
    buffer = read(fd, temp, BUFFER_SIZE);
    temp[buffer] = '\0';
 //   printf("TEMP:\n %s\n", temp); //tester temp
    size = ft_strlen_mod(temp, '\n', index);
 //   printf("2nd test:\n index %ld size %ld\n", index, size); //tester ints
    dest = malloc((size + 2) *  sizeof(char));
/*     if (!dest)
        return (MALLOC_ERROR); */
    ft_strlcpy_mod(dest, temp, '\n', index);
 //   printf("DEST:\n %s\n", dest);
    index = size;
 //   printf("2nd test:\n index %ld size %ld\n", index, size); //tester ints
    if (temp[index] != '\0')
    {
        size = ft_strlen_mod(temp, '\0', index);
//        printf("3rd test:\n  index %ld\n size %ld\n", index, size); //tester ints
		rest = malloc(100 * sizeof(char));
/*         if (!rest)
            return (MALLOC_ERROR); */
        ft_strlcpy_mod(rest, temp, '\0', index);

    }
//    printf("REST:\n %s\n\n", rest); //tester rest
    dest[index] = '\n'; //adicionar um enter a mais na saída do dest
    index++;
    dest[index] = '\0';
//    printf("DEST:\n %s", dest);
}