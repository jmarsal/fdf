/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:02:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/25 22:30:36 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	Applique la fonction f à chaque caractère de la chaine de ca- ractères
**	passée en paramètre pour créer une nouvelle chaine “fraiche”
**	(avec malloc(3)) résultant des applications succes- sives de f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
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
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
