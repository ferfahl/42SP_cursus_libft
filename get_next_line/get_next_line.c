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

void   get_next_line(int fd) //char *
{
    char *dest;
    char *temp;
    int index;
    int size;

    //verificações de erro
    //fd < 0/
    index = 0;
    temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
    
    read(fd, temp, BUFFER_SIZE);
//    printf("%s\n", temp);
    temp[BUFFER_SIZE] = '\0';
    while (temp[index] != '\n')
    {
        size++;
        index++;
    }
    index = 0;
    dest = malloc((size + 2) *  sizeof(char));
    while (temp[index] != '\n')
    {
        dest[index] = temp[index];
        index++;
    }
    dest[index] = '\n';
    index++;
    dest[index] = '\0';
    //adicionar um enter a mais na saída do dest
    printf("%s", dest);
}