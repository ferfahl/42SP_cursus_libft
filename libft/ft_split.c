/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:09:53 by feralves          #+#    #+#             */
/*   Updated: 2022/07/08 03:19:03 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_word(char **dest, char const *src, char c) //alocar as 'palavras' em cada posição da string
{
	unsigned int k;
	size_t len;
	unsigned int start;
	int i;

	i = 0;
	k = 0;
	len = 0;
	start = 0;
	while (src[k] != '\0')
	{
		start = k; //valor da 2a palavra tem que seguir o k para não repetir
		if (k == 0 && src[k] == c)
		{
			start++;
			k++;
		}
		while (src[k] == c)
		{
			start++;
			k++;
		}
		//start = posição inicial da string
		while (src[k] != c && src[k] != '\0')
		{
			len++;
			k++;
		}
		dest[i] = ft_substr(src, start, len);
		len = 0;
		i++;
		if (src[k] != 0)
			k++;
	}
	i--;
	dest[i] = NULL;////fim da string
}

char	**ft_split(char const *s, char c) //list = {"str1", "str2", "str3", ... "strn", NULL};
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
		if (s[i] == c && s[i - 1] != c && i != 0) //contando as separações, verificando duplicadas e não contabilizando se no inicio
			count++;
		i++;
	}
	if (s[i - 1] != c)
		count++; //i = qtd palavras +1;
	list = malloc(sizeof(char *)*(count + 1));
	//list = malloc(qtd caracters + qt palavras(\0)byte NULL)
	if (!list)
		return (NULL);//if (!list) -> checar alocagem
	ft_word(list, s, c);
	return (list);//retorno "string de string" -> cada string em uma posição
}
