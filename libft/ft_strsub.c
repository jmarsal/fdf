/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 21:59:30 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/25 11:43:10 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un tronçon de la
**	chaine de caractères passée en paramètre. Le tronçon commence à l’index
**	start et à pour longueur len. Si start et len ne désignent pas un tronçon
**	de chaine valide, le comportement est indéterminé. Si l’allocation
**	échoue, la fonction renvoie NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			while (start--)
				s++;
			str = ft_strncpy(str, s, len);
			str[len] = '\0';
		}
		return (str);
	}
	return (NULL);
}
