/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:07:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/28 15:11:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	ptr = NULL;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			ptr = (char*)s + i;
		i++;
	}
	return (ptr);
}
