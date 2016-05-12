/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:31:33 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/25 22:19:50 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	Prend en paramètre l’adresse d’un pointeur dont la zone pointée
**	doit être libérée avec free(3), puis le pointeur est mis à NULL.
*/

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
