/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 12:24:53 by jmarsal           #+#    #+#             */
/*   Updated: 2016/01/10 14:30:29 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bck;
	unsigned char	replace;
	size_t			i;

	bck = (unsigned char *)b;
	replace = (unsigned char)c;
	i = 0;
	while (i < len)
		bck[i++] = replace;
	return (b);
}
