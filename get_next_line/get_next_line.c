/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:07:10 by feralves          #+#    #+#             */
/*   Updated: 2022/07/18 02:07:11 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_mod(const char *str, char a, size_t count)
{
	while (str[count] != a)
	{
		count++;
	}
	return (count);
}

void   get_next_line(int fd) //char *
{
    char *dest;
    char *temp;
    static char *rest;
    size_t index;
    size_t size;
    int second_index;
    int another;

    //verificações de erro
    //fd < 0/
    index = 0;
    second_index = 0;
    size = 0;
    another = 0;
/*     if (rest)
    {
        
    } */
    temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
    read(fd, temp, BUFFER_SIZE);
    printf("%s\n", temp);
    temp[BUFFER_SIZE] = '\0';
    size = ft_strlen_mod(temp, '\n', index);
    dest = malloc((size + 2) *  sizeof(char));
    while (temp[index] != '\n')
    {
        dest[index] = temp[index];
        index++;
    }
    printf("1 index %ld\n size %ld\n second_index %d\n", index, size, second_index);
    if (temp[index] != '\0')
    {
        size = ft_strlen_mod(temp, '\n', index);
        printf("2 index %ld\n size %ld\n second_index %d\n", index, size, second_index);
        rest = malloc((size + 1) * sizeof(char));
        printf("3 index %ld\n size %ld\n second_index %d\n", index, size, second_index);
        another = index;
        printf("4 index %ld\n size %ld\n second_index %d\n", index, size, second_index);
        while (temp[index] != '\0')
        {
            rest[second_index] = temp[index];
            index++;
            second_index++;
        }
        printf("5 index %ld\n size %ld\n second_index %d\n", index, size, second_index);
    }
    printf("%s\n\n", rest);
    dest[another] = '\n'; //adicionar um enter a mais na saída do dest
    another++;
    dest[another] = '\0';
    printf("%s", dest);
}