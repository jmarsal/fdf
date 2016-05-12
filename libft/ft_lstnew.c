/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:34:30 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/07 15:54:08 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	Alloue (avec malloc(3)) et retourne un maillon “frais”. Les champs content
**	et content_size du nouveau maillon sont initialisés par copie des
**	paramètres de la fonction. Si le paramètre content est nul, le champs
**	content est initialisé à NULL et le champs content_size est initialisé à
**	0 quelque soit la valeur du paramètre content_size. Le champ next est
**	initialisé à NULL. Si l’allocation échoue, la fonction renvoie NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = ft_memalloc(content_size);
		if (newlist->content == NULL)
			return (NULL);
		ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
