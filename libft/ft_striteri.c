/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:42:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/02 11:06:25 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applique la fonction f à chaque caractère de la chaine de caractères
**	passée en paramètre en précisant son index en pre- mier argument. Chaque
**	caractère est passé par adresse à la fonction f afin de pouvoir être
**	modifié si nécéssaire.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}
