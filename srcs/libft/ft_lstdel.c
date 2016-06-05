/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:53:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/02 10:25:20 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	Prend en paramètre l’adresse d’un pointeur sur un maillon et libère la
**	mémoire de ce maillon et celle de tous ses successeurs l’un après l’autre
**	avec del et free(3). Pour terminer, le pointeur sur le premier maillon
**	maintenant libéré doit être mis à NULL (de manière similaire à la
**	fonction ft_memdel de la partie obligatoire).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*next_lst;

	lst = *alst;
	while (lst)
	{
		next_lst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = next_lst;
	}
	*alst = NULL;
}
