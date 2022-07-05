/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:04:48 by feralves          #+#    #+#             */
/*   Updated: 2022/06/17 02:48:10 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	bigcount;
	size_t	littlecount;

	bigcount = 0;
	littlecount = 0;
	count = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[count] != '\0' && count <= len - ft_strlen(little))
	{
		while (big[bigcount++] == little[littlecount++])
		{
			if (little[littlecount] == '\0')
				return ((char *)&big[count]);
		}
		littlecount = 0;
		count++;
		bigcount = count;
	}
	return (0);
}
