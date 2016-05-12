/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 23:25:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/29 23:26:31 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	cpy_dest = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	while (n--)
	{
		*cpy_dest = *cpy_src;
		if (*cpy_src == (unsigned char)c)
			return ((void*)(cpy_dest + 1));
		cpy_dest++;
		cpy_src++;
	}
	return (NULL);
}
