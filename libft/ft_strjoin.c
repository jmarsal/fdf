/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:34:38 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/25 22:37:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne une chaine de caractères “fraiche”
**	terminée par un ’\0’ résultant de la concaténation de s1 et s2. Si
**	l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new_str;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		new_str = (char*)malloc(sizeof(char) * i + 1);
		if (new_str)
		{
			new_str = ft_strcpy(new_str, s1);
			new_str = ft_strcat(new_str, s2);
			new_str[i + 1] = '\0';
			return (new_str);
		}
	}
	return (NULL);
}
