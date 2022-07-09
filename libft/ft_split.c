/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:09:53 by feralves          #+#    #+#             */
/*   Updated: 2022/07/10 01:06:28 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_word(char **dest, char const *src, char c)
{
	size_t			len;
	unsigned int	start;
	size_t			i;

	i = 0;
	len = 0;
	start = 0;
	while (src[start + len] != '\0')
	{
		while (src[start + len] == c && src[start + len] != '\0')
			start++;
		while (src[start + len] != c && src[start + len] != '\0')
			len++;
		if (len != 0)
		{
			dest[i] = ft_substr(src, start, len);
			start = start + len;
			len = 0;
			i++;
		}
	}
	dest[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			count++;
		i++;
	}
	if (i != 0 && s[i - 1] != c && ft_strlen(s) > 0)
		count++;
	list = malloc(sizeof(char *) * (count + 1));
	if (!list)
		return (NULL);
	ft_word(list, s, c);
	return (list);
}
