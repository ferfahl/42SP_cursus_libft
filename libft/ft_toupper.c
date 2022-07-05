/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:45:01 by feralves          #+#    #+#             */
/*   Updated: 2022/06/17 02:48:32 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	// REEMOVER CAVALINHO DO MAKEFILE!!!!!!!!!!!!
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	else
		return (c);
}
