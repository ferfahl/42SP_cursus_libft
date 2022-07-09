/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:05:03 by feralves          #+#    #+#             */
/*   Updated: 2022/07/09 05:26:35 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	dest = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	while (s2[i] != '\0')
	{
		dest[count + i] = s2[i];
		i++;
	}
	dest[count + i] = '\0';
	return (dest);
}
