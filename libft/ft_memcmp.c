/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 09:34:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/29 22:55:31 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;

	cpy_s1 = (unsigned char*)s1;
	cpy_s2 = (unsigned char*)s2;
	while (n--)
	{
		if (*cpy_s1 != *cpy_s2)
			return (*cpy_s1 - *cpy_s2);
		cpy_s1++;
		cpy_s2++;
	}
	return (0);
}
