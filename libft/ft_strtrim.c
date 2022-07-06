/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:08:12 by feralves          #+#    #+#             */
/*   Updated: 2022/07/06 03:03:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int start;
	int lenght;
	int size;
	char *dest;
	
	lenght = ft_strlen(s1);
	start = 0;
	size = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (lenght >= 0 && ft_strchr(set, s1[lenght]))
		lenght--;
	if (start < lenght)
		dest = malloc((lenght - start) + 2);
	else
		dest = malloc(1);
	if (!dest)
		return (NULL);
	while (start <= lenght)
		dest[size++] = s1[start++];
	dest[size] = '\0';
	return (dest);
}
