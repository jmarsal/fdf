/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 13:33:10 by jmarsal           #+#    #+#             */
/*   Updated: 2015/12/19 09:47:25 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	char		*t_dest;
	const char	*t_src;
	size_t		i;

	t_dest = dest;
	t_src = src;
	i = 0;
	while (*t_dest)
		t_dest++;
	while (t_src[i] && i < nb)
	{
		*t_dest = t_src[i];
		t_dest++;
		i++;
	}
	*t_dest = '\0';
	return (dest);
}
