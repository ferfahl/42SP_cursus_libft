/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:26:35 by feralves          #+#    #+#             */
/*   Updated: 2022/06/19 20:11:16 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*ret;

	str = (char *)s;
	ret = 0;
	if ((char)c == '\0')
		return (&str[ft_strlen(str)]);
	while (*str != '\0')
	{
		if (*str == (char)c)
			ret = str;
		str++;
	}
	return (ret);
}
