/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:47:42 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/02 11:08:06 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	Alloue (avec malloc(3)) et retourne une chaine de caractère “fraiche”
**	terminée par un ’\0’. Chaque caractère de la chaine est initialisé à
**	’\0’. Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}
