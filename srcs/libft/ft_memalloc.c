/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:23:14 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/25 12:12:02 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	Alloue (avec malloc(3)) et retourne une zone de mémoire “fraiche”.
**	La mémoire allouée est initialisée à 0. Si l’allocation échoue,
**	la fonction renvoie NULL.
*/

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	size_t			i;

	mem = NULL;
	mem = (unsigned char *)malloc(size);
	if (mem)
	{
		i = 0;
		while (size--)
			mem[i++] = 0;
	}
	return ((void *)mem);
}
