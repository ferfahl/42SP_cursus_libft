/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:09:53 by feralves          #+#    #+#             */
/*   Updated: 2022/07/06 03:34:20 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char **list;
	int count;
	int i;
	int j;

	j = 0;
	i = 0;
	count = 0;
	while (s[i] != '\0')//contar qtd de palavras/strings separadas por "c"
	{
		if (s[i] == c)
			count++;
		i++;
	}
	count++; //i = qtd palavras +1;
	list = malloc(count + 1);//list = malloc(qtd palavras + 1 //byte NULL)
	if (!list)
		return (NULL);//if (!list) -> checar alocagem

	//alocar as 'palavras' em cada posição da string
	//*list[j] = NULL;
	//retorno "string de string" -> cada string em uma posição
}