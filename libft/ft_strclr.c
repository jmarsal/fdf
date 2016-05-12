/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:02:58 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/25 22:25:36 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Assigne la valeur ’\0’ à tous les caractères de la chaine passée en
**	paramètre.
*/

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s != '\0')
			*s++ = '\0';
	}
}
