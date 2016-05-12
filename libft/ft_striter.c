/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:14:37 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/02 11:16:46 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applique la fonction f à chaque caractère de la chaine de caractères
**	passée en paramètre. Chaque caractère est passé par adresse à la
**	fonction f afin de pouvoir être modifié si nécéssaire.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (s && *s)
			f(s++);
	}
}
