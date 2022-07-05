/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:29:00 by feralves          #+#    #+#             */
/*   Updated: 2022/07/02 03:16:39 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int number)
{
	int	count;

	count = 0;

	while (number >= 10)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n) 
{
	int		size;
	int		negative;
	char	*string;

	negative = 0;
	size = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	size = (ft_counter(n) + negative + 1);
	string = malloc(size);
	if (!string)
		return (NULL);
	if (negative)
		string[0] = '-';
	string[size] = '\0';
	size--;
	while (size - negative >= 0)
	{
		string[size] = '0' + (n % 10);
		n = n / 10;
		size--;
	}
	return (string);
}
