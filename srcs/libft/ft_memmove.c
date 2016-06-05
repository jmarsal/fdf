/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:12:38 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/30 00:50:16 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	if (dst > src)
	{
		t_dst = t_dst + len;
		t_src = t_src + len;
		while (len--)
			*--t_dst = *--t_src;
	}
	else
		ft_memcpy(dst, src, len);
	return ((unsigned char *)dst);
}
