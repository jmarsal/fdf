/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:40:56 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/02 10:27:07 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	Prend en paramètre l’adresse d’un pointeur sur un maillon et libère la
**	mémoire du contenu de ce maillon avec la fonction del passée en paramètre
**	puis libère la mémoire du maillon en lui même avec free(3). La mémoire
**	du champ next ne doit en aucun cas être libérée. Pour terminer, le
**	pointeur sur le maillon maintenant libéré doit être mis à NULL (de
**	manière similaire à la fonction ft_memdel de la partie obligatoire).
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
