/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:59:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/06/03 10:02:10 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	coords_add_end(t_coords **alst, t_coords *new)
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
