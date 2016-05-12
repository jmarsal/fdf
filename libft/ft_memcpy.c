/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:43:56 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/29 23:29:19 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	cpy_dest = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	while (n--)
		*cpy_dest++ = *cpy_src++;
	return (dst);
}
