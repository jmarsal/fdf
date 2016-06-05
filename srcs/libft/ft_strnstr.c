/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:18:37 by jmarsal           #+#    #+#             */
/*   Updated: 2016/01/09 12:57:33 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;

	if (*little == '\0')
		return ((char *)big);
	count = ft_strlen(little);
	while (*big != '\0' && len-- >= count)
	{
		if (*big == *little && ft_memcmp(big, little, count) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
