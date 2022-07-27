/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:07:14 by feralves          #+#    #+#             */
/*   Updated: 2022/07/18 02:07:15 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Libraries
//to use malloc & free
#include <stdlib.h>
//to use read
#include <unistd.h>

//REMOVER
#include <stdio.h>

//Functions
void get_next_line(int fd); //char *

#endif