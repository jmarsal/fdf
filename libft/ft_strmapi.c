/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:32:36 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/02 11:16:15 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	Applique la fonction f à chaque caractère de la chaine de caractères
**	passée en paramètre en précisant son index pour créer une nouvelle
**	chaine “fraiche” (avec malloc(3)) résultant des applications successives
**	de f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	if ((str = ft_strnew(length)) == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
