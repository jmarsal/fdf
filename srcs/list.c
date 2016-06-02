/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:06:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/02 16:13:20 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	lst_coords_push_end(t_coords **alst, t_coords *new)
{
	t_coords	*cur;

	cur = *alst;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	else
		*alst = new;
}
