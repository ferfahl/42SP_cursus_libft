/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:59:31 by feralves          #+#    #+#             */
/*   Updated: 2022/07/09 05:27:40 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	count;
	size_t			max_size;

	count = 0;
	max_size = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	max_size = ft_strlen(s) - start;
	if (max_size > len)
		max_size = len;
	substring = malloc(max_size + 1);
	if (!substring)
		return (NULL);
	while (count < max_size)
	{
		substring[count] = s[start];
		start++;
		count++;
	}
	substring[count] = '\0';
	return (substring);
}
